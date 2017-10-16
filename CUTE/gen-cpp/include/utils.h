#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAXSIZE 10000

const char *HOST = "129.175.35.4";
const int PORT = 80;

const char *PREFIX = "http://yago-knowledge.org/resource/";

class HttpGet {

public:
    bool parseURI(std::string &_return, const std::string &entityURL) {

        if (entityURL.find(PREFIX) != std::string::npos) {
            _return = entityURL.substr(strlen(PREFIX));
            return true;
        }
        _return = entityURL;
        return false;
    }

    void httpsend(std::vector<std::vector<std::string> > & _result, std::string sparql) {

        std::string parameters = sparql;
        for (int i = 0; i < parameters.length(); i++) {
            if (parameters[i] == ' ') {
                parameters.erase(i, 1);
                parameters.insert(i, "%20");
            }
            else if (parameters[i] == '+') {
                parameters.erase(i, 1);
                parameters.insert(i, "%2B");
            }
            else if (parameters[i] == '?') {
                parameters.erase(i, 1);
                parameters.insert(i, "%3F");
            }
            else if (parameters[i] == '{') {
                parameters.erase(i, 1);
                parameters.insert(i, "%7B");
            }
            else if (parameters[i] == '<') {
                parameters.erase(i, 1);
                parameters.insert(i, "%3C");
            }
            else if (parameters[i] == '>') {
                parameters.erase(i, 1);
                parameters.insert(i, "%3E");
            }
            else if (parameters[i] == '"') {
                parameters.erase(i, 1);
                parameters.insert(i, "%22");
            }
            else if (parameters[i] == '\n') {
                parameters.erase(i, 1);
                parameters.insert(i, "%0A");
            }
            else if (parameters[i] == '#') {
                parameters.erase(i, 1);
                parameters.insert(i, "%23");
            }
            else if (parameters[i] == '&') {
                parameters.erase(i, 1);
                parameters.insert(i, "%26");
            }
        }
        parameters = "query=" + parameters + "&format=text%2Fcsv";

        
        int clientfd;
        struct sockaddr_in serveraddr;
        struct hostent *hp = NULL;

        if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            exit(-1);
        
        bzero((char *) &serveraddr, sizeof(serveraddr));
        serveraddr.sin_family = AF_INET;
        inet_aton(HOST, &serveraddr.sin_addr);
        serveraddr.sin_port = htons(PORT);

        if (connect(clientfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
            exit(-1);

        
        char request[MAXSIZE];
        
        sprintf(request, "GET /sparql?%s HTTP/1.1\r\n", parameters.c_str());
        strcat(request, "Host: ");
        strcat(request, HOST);
        strcat(request, "\r\n");
        strcat(request, "Accept: */*\r\n");
        strcat(request, "Connection: close\r\n\r\n");
        

        send(clientfd, request, strlen(request), 0);

        char tmp[MAXSIZE + 10];
        std::string str = "";

        while(1) {
            int cv;
            if ((cv = recv(clientfd, tmp, MAXSIZE, 0)) < 0)
                exit(-1);
            if (cv == 0) break;
            for (int i = 0; i < cv; i++)
                str += tmp[i];
        }

        // find the beginning of the csv
        str = str.substr(str.find("\r\n\r\n") + 4);

        // ignore the first line
        str = str.substr(str.find("\n") + 1);


        std::vector<std::string> lines;

        int last = 0;
        for (int i = 1; i < str.length(); i++)
            if (str[i - 1] == '"' && str[i] == '\n' && (str[i + 1] == '"' || i == str.length() - 1)) {
                std::string tmp = "";
                for (int j = last; j <= i - 1; j++)
                    tmp += str[j];
                last = i + 1;
                lines.push_back(tmp);
            }

    
        std::cout << "records: " << lines.size() << std::endl << std::endl;
        
        //FILE *fp = fopen("/Users/wzc/Desktop/log.txt", "w");
        for (int it = 0; it < lines.size(); it++) {
            std::vector<std::string> tmp;
            std::string s = lines[it];
            //fprintf(fp, "%d: %s\n", it + 1, s.c_str());
            //fflush(fp);
            int last = 0;
            for (int i = 0; i < s.length() - 2; i++) {

                if (s[i] == '"' && s[i + 1] == ',' && (s[i + 2] == '"' || (s[i + 2] >= '0' && s[i + 2] <= '9'))) {
                    std::string token = "";

                    for (int j = last + 1; j <= i - 1; j++)
                        token += s[j];

                    if (s[i + 2] == '"') last = i + 2;
                    else last = i + 1;
                    tmp.push_back(token);
                    
                }
            }
            std::string token = "";
            for (int j = last + 1; j < s.length() - 1; j++)
                token += s[j];

            tmp.push_back(token);

            /*
            size_t pos = 0;
            std::string token;
            while ((pos = (*it).find(",")) != std::string::npos) {
                token = (*it).substr(0, pos);
                tmp.push_back(token);
                s.erase(0, pos + 1);
            }
            tmp.push_back(s.substr(0, s.length()-1));
            */

            _result.push_back(tmp);
        }
    }

};

