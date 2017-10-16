#include "utils.h"

int main(int argc, char* argv[])
{
	string url = "";
	url += "SELECT ?s ?p WHERE {";
	url += "\n";
	url += "?s ?p <http://yago-knowledge.org/resource/Barack_Obama> .\n";
	url += "?s ?p <http://yago-knowledge.org/resource/Xi_Jinping>   .\n";
	url += "FILTER (\n";
	url += "STR(?p) != \"http://www.w3.org/1999/02/22-rdf-syntax-ns#type\"";
	url += "\n";
	url += ")\n";
	url += "}\n";
	cout << url << endl;

	HttpGet http;
	vector< vector<string> > s_ = http.httpsend(url);

	for (int i = 0; i < s_.size(); i++)
	{
		for (int j = 0; j < s_[0].size(); j++)
		{
			cout << http.parseURI(s_[i][j]) << endl;
		}
	}
	return 0;
}
