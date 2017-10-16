/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef DemoServlet_H
#define DemoServlet_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "server_types.h"

namespace demo {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class DemoServletIf {
 public:
  virtual ~DemoServletIf() {}
  virtual void disambiguation(std::vector<OneRowCandidate> & _return, const std::vector<std::vector<std::string> > & rawInput) = 0;
  virtual void findCommonInfo(CommonInfo& _return, const std::vector<std::vector<std::string> > & input, const bool requirePattern) = 0;
  virtual void query(SparqlAndResult& _return, const CommonInfo& info, const std::vector<std::vector<std::string> > & input) = 0;
  virtual void queryWithNeg(SparqlAndResult& _return, const NegCommonInfo& negInfo, const std::string& sparql) = 0;
};

class DemoServletIfFactory {
 public:
  typedef DemoServletIf Handler;

  virtual ~DemoServletIfFactory() {}

  virtual DemoServletIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(DemoServletIf* /* handler */) = 0;
};

class DemoServletIfSingletonFactory : virtual public DemoServletIfFactory {
 public:
  DemoServletIfSingletonFactory(const boost::shared_ptr<DemoServletIf>& iface) : iface_(iface) {}
  virtual ~DemoServletIfSingletonFactory() {}

  virtual DemoServletIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(DemoServletIf* /* handler */) {}

 protected:
  boost::shared_ptr<DemoServletIf> iface_;
};

class DemoServletNull : virtual public DemoServletIf {
 public:
  virtual ~DemoServletNull() {}
  void disambiguation(std::vector<OneRowCandidate> & /* _return */, const std::vector<std::vector<std::string> > & /* rawInput */) {
    return;
  }
  void findCommonInfo(CommonInfo& /* _return */, const std::vector<std::vector<std::string> > & /* input */, const bool /* requirePattern */) {
    return;
  }
  void query(SparqlAndResult& /* _return */, const CommonInfo& /* info */, const std::vector<std::vector<std::string> > & /* input */) {
    return;
  }
  void queryWithNeg(SparqlAndResult& /* _return */, const NegCommonInfo& /* negInfo */, const std::string& /* sparql */) {
    return;
  }
};

typedef struct _DemoServlet_disambiguation_args__isset {
  _DemoServlet_disambiguation_args__isset() : rawInput(false) {}
  bool rawInput :1;
} _DemoServlet_disambiguation_args__isset;

class DemoServlet_disambiguation_args {
 public:

  DemoServlet_disambiguation_args(const DemoServlet_disambiguation_args&);
  DemoServlet_disambiguation_args& operator=(const DemoServlet_disambiguation_args&);
  DemoServlet_disambiguation_args() {
  }

  virtual ~DemoServlet_disambiguation_args() throw();
  std::vector<std::vector<std::string> >  rawInput;

  _DemoServlet_disambiguation_args__isset __isset;

  void __set_rawInput(const std::vector<std::vector<std::string> > & val);

  bool operator == (const DemoServlet_disambiguation_args & rhs) const
  {
    if (!(rawInput == rhs.rawInput))
      return false;
    return true;
  }
  bool operator != (const DemoServlet_disambiguation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DemoServlet_disambiguation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DemoServlet_disambiguation_pargs {
 public:


  virtual ~DemoServlet_disambiguation_pargs() throw();
  const std::vector<std::vector<std::string> > * rawInput;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DemoServlet_disambiguation_result__isset {
  _DemoServlet_disambiguation_result__isset() : success(false) {}
  bool success :1;
} _DemoServlet_disambiguation_result__isset;

class DemoServlet_disambiguation_result {
 public:

  DemoServlet_disambiguation_result(const DemoServlet_disambiguation_result&);
  DemoServlet_disambiguation_result& operator=(const DemoServlet_disambiguation_result&);
  DemoServlet_disambiguation_result() {
  }

  virtual ~DemoServlet_disambiguation_result() throw();
  std::vector<OneRowCandidate>  success;

  _DemoServlet_disambiguation_result__isset __isset;

  void __set_success(const std::vector<OneRowCandidate> & val);

  bool operator == (const DemoServlet_disambiguation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DemoServlet_disambiguation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DemoServlet_disambiguation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DemoServlet_disambiguation_presult__isset {
  _DemoServlet_disambiguation_presult__isset() : success(false) {}
  bool success :1;
} _DemoServlet_disambiguation_presult__isset;

class DemoServlet_disambiguation_presult {
 public:


  virtual ~DemoServlet_disambiguation_presult() throw();
  std::vector<OneRowCandidate> * success;

  _DemoServlet_disambiguation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DemoServlet_findCommonInfo_args__isset {
  _DemoServlet_findCommonInfo_args__isset() : input(false), requirePattern(false) {}
  bool input :1;
  bool requirePattern :1;
} _DemoServlet_findCommonInfo_args__isset;

class DemoServlet_findCommonInfo_args {
 public:

  DemoServlet_findCommonInfo_args(const DemoServlet_findCommonInfo_args&);
  DemoServlet_findCommonInfo_args& operator=(const DemoServlet_findCommonInfo_args&);
  DemoServlet_findCommonInfo_args() : requirePattern(0) {
  }

  virtual ~DemoServlet_findCommonInfo_args() throw();
  std::vector<std::vector<std::string> >  input;
  bool requirePattern;

  _DemoServlet_findCommonInfo_args__isset __isset;

  void __set_input(const std::vector<std::vector<std::string> > & val);

  void __set_requirePattern(const bool val);

  bool operator == (const DemoServlet_findCommonInfo_args & rhs) const
  {
    if (!(input == rhs.input))
      return false;
    if (!(requirePattern == rhs.requirePattern))
      return false;
    return true;
  }
  bool operator != (const DemoServlet_findCommonInfo_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DemoServlet_findCommonInfo_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DemoServlet_findCommonInfo_pargs {
 public:


  virtual ~DemoServlet_findCommonInfo_pargs() throw();
  const std::vector<std::vector<std::string> > * input;
  const bool* requirePattern;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DemoServlet_findCommonInfo_result__isset {
  _DemoServlet_findCommonInfo_result__isset() : success(false) {}
  bool success :1;
} _DemoServlet_findCommonInfo_result__isset;

class DemoServlet_findCommonInfo_result {
 public:

  DemoServlet_findCommonInfo_result(const DemoServlet_findCommonInfo_result&);
  DemoServlet_findCommonInfo_result& operator=(const DemoServlet_findCommonInfo_result&);
  DemoServlet_findCommonInfo_result() {
  }

  virtual ~DemoServlet_findCommonInfo_result() throw();
  CommonInfo success;

  _DemoServlet_findCommonInfo_result__isset __isset;

  void __set_success(const CommonInfo& val);

  bool operator == (const DemoServlet_findCommonInfo_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DemoServlet_findCommonInfo_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DemoServlet_findCommonInfo_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DemoServlet_findCommonInfo_presult__isset {
  _DemoServlet_findCommonInfo_presult__isset() : success(false) {}
  bool success :1;
} _DemoServlet_findCommonInfo_presult__isset;

class DemoServlet_findCommonInfo_presult {
 public:


  virtual ~DemoServlet_findCommonInfo_presult() throw();
  CommonInfo* success;

  _DemoServlet_findCommonInfo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DemoServlet_query_args__isset {
  _DemoServlet_query_args__isset() : info(false), input(false) {}
  bool info :1;
  bool input :1;
} _DemoServlet_query_args__isset;

class DemoServlet_query_args {
 public:

  DemoServlet_query_args(const DemoServlet_query_args&);
  DemoServlet_query_args& operator=(const DemoServlet_query_args&);
  DemoServlet_query_args() {
  }

  virtual ~DemoServlet_query_args() throw();
  CommonInfo info;
  std::vector<std::vector<std::string> >  input;

  _DemoServlet_query_args__isset __isset;

  void __set_info(const CommonInfo& val);

  void __set_input(const std::vector<std::vector<std::string> > & val);

  bool operator == (const DemoServlet_query_args & rhs) const
  {
    if (!(info == rhs.info))
      return false;
    if (!(input == rhs.input))
      return false;
    return true;
  }
  bool operator != (const DemoServlet_query_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DemoServlet_query_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DemoServlet_query_pargs {
 public:


  virtual ~DemoServlet_query_pargs() throw();
  const CommonInfo* info;
  const std::vector<std::vector<std::string> > * input;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DemoServlet_query_result__isset {
  _DemoServlet_query_result__isset() : success(false) {}
  bool success :1;
} _DemoServlet_query_result__isset;

class DemoServlet_query_result {
 public:

  DemoServlet_query_result(const DemoServlet_query_result&);
  DemoServlet_query_result& operator=(const DemoServlet_query_result&);
  DemoServlet_query_result() {
  }

  virtual ~DemoServlet_query_result() throw();
  SparqlAndResult success;

  _DemoServlet_query_result__isset __isset;

  void __set_success(const SparqlAndResult& val);

  bool operator == (const DemoServlet_query_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DemoServlet_query_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DemoServlet_query_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DemoServlet_query_presult__isset {
  _DemoServlet_query_presult__isset() : success(false) {}
  bool success :1;
} _DemoServlet_query_presult__isset;

class DemoServlet_query_presult {
 public:


  virtual ~DemoServlet_query_presult() throw();
  SparqlAndResult* success;

  _DemoServlet_query_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DemoServlet_queryWithNeg_args__isset {
  _DemoServlet_queryWithNeg_args__isset() : negInfo(false), sparql(false) {}
  bool negInfo :1;
  bool sparql :1;
} _DemoServlet_queryWithNeg_args__isset;

class DemoServlet_queryWithNeg_args {
 public:

  DemoServlet_queryWithNeg_args(const DemoServlet_queryWithNeg_args&);
  DemoServlet_queryWithNeg_args& operator=(const DemoServlet_queryWithNeg_args&);
  DemoServlet_queryWithNeg_args() : sparql() {
  }

  virtual ~DemoServlet_queryWithNeg_args() throw();
  NegCommonInfo negInfo;
  std::string sparql;

  _DemoServlet_queryWithNeg_args__isset __isset;

  void __set_negInfo(const NegCommonInfo& val);

  void __set_sparql(const std::string& val);

  bool operator == (const DemoServlet_queryWithNeg_args & rhs) const
  {
    if (!(negInfo == rhs.negInfo))
      return false;
    if (!(sparql == rhs.sparql))
      return false;
    return true;
  }
  bool operator != (const DemoServlet_queryWithNeg_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DemoServlet_queryWithNeg_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DemoServlet_queryWithNeg_pargs {
 public:


  virtual ~DemoServlet_queryWithNeg_pargs() throw();
  const NegCommonInfo* negInfo;
  const std::string* sparql;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DemoServlet_queryWithNeg_result__isset {
  _DemoServlet_queryWithNeg_result__isset() : success(false) {}
  bool success :1;
} _DemoServlet_queryWithNeg_result__isset;

class DemoServlet_queryWithNeg_result {
 public:

  DemoServlet_queryWithNeg_result(const DemoServlet_queryWithNeg_result&);
  DemoServlet_queryWithNeg_result& operator=(const DemoServlet_queryWithNeg_result&);
  DemoServlet_queryWithNeg_result() {
  }

  virtual ~DemoServlet_queryWithNeg_result() throw();
  SparqlAndResult success;

  _DemoServlet_queryWithNeg_result__isset __isset;

  void __set_success(const SparqlAndResult& val);

  bool operator == (const DemoServlet_queryWithNeg_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DemoServlet_queryWithNeg_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DemoServlet_queryWithNeg_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DemoServlet_queryWithNeg_presult__isset {
  _DemoServlet_queryWithNeg_presult__isset() : success(false) {}
  bool success :1;
} _DemoServlet_queryWithNeg_presult__isset;

class DemoServlet_queryWithNeg_presult {
 public:


  virtual ~DemoServlet_queryWithNeg_presult() throw();
  SparqlAndResult* success;

  _DemoServlet_queryWithNeg_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class DemoServletClient : virtual public DemoServletIf {
 public:
  DemoServletClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  DemoServletClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void disambiguation(std::vector<OneRowCandidate> & _return, const std::vector<std::vector<std::string> > & rawInput);
  void send_disambiguation(const std::vector<std::vector<std::string> > & rawInput);
  void recv_disambiguation(std::vector<OneRowCandidate> & _return);
  void findCommonInfo(CommonInfo& _return, const std::vector<std::vector<std::string> > & input, const bool requirePattern);
  void send_findCommonInfo(const std::vector<std::vector<std::string> > & input, const bool requirePattern);
  void recv_findCommonInfo(CommonInfo& _return);
  void query(SparqlAndResult& _return, const CommonInfo& info, const std::vector<std::vector<std::string> > & input);
  void send_query(const CommonInfo& info, const std::vector<std::vector<std::string> > & input);
  void recv_query(SparqlAndResult& _return);
  void queryWithNeg(SparqlAndResult& _return, const NegCommonInfo& negInfo, const std::string& sparql);
  void send_queryWithNeg(const NegCommonInfo& negInfo, const std::string& sparql);
  void recv_queryWithNeg(SparqlAndResult& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class DemoServletProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<DemoServletIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (DemoServletProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_disambiguation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_findCommonInfo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_query(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_queryWithNeg(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  DemoServletProcessor(boost::shared_ptr<DemoServletIf> iface) :
    iface_(iface) {
    processMap_["disambiguation"] = &DemoServletProcessor::process_disambiguation;
    processMap_["findCommonInfo"] = &DemoServletProcessor::process_findCommonInfo;
    processMap_["query"] = &DemoServletProcessor::process_query;
    processMap_["queryWithNeg"] = &DemoServletProcessor::process_queryWithNeg;
  }

  virtual ~DemoServletProcessor() {}
};

class DemoServletProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  DemoServletProcessorFactory(const ::boost::shared_ptr< DemoServletIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< DemoServletIfFactory > handlerFactory_;
};

class DemoServletMultiface : virtual public DemoServletIf {
 public:
  DemoServletMultiface(std::vector<boost::shared_ptr<DemoServletIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~DemoServletMultiface() {}
 protected:
  std::vector<boost::shared_ptr<DemoServletIf> > ifaces_;
  DemoServletMultiface() {}
  void add(boost::shared_ptr<DemoServletIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void disambiguation(std::vector<OneRowCandidate> & _return, const std::vector<std::vector<std::string> > & rawInput) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->disambiguation(_return, rawInput);
    }
    ifaces_[i]->disambiguation(_return, rawInput);
    return;
  }

  void findCommonInfo(CommonInfo& _return, const std::vector<std::vector<std::string> > & input, const bool requirePattern) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->findCommonInfo(_return, input, requirePattern);
    }
    ifaces_[i]->findCommonInfo(_return, input, requirePattern);
    return;
  }

  void query(SparqlAndResult& _return, const CommonInfo& info, const std::vector<std::vector<std::string> > & input) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->query(_return, info, input);
    }
    ifaces_[i]->query(_return, info, input);
    return;
  }

  void queryWithNeg(SparqlAndResult& _return, const NegCommonInfo& negInfo, const std::string& sparql) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->queryWithNeg(_return, negInfo, sparql);
    }
    ifaces_[i]->queryWithNeg(_return, negInfo, sparql);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class DemoServletConcurrentClient : virtual public DemoServletIf {
 public:
  DemoServletConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  DemoServletConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void disambiguation(std::vector<OneRowCandidate> & _return, const std::vector<std::vector<std::string> > & rawInput);
  int32_t send_disambiguation(const std::vector<std::vector<std::string> > & rawInput);
  void recv_disambiguation(std::vector<OneRowCandidate> & _return, const int32_t seqid);
  void findCommonInfo(CommonInfo& _return, const std::vector<std::vector<std::string> > & input, const bool requirePattern);
  int32_t send_findCommonInfo(const std::vector<std::vector<std::string> > & input, const bool requirePattern);
  void recv_findCommonInfo(CommonInfo& _return, const int32_t seqid);
  void query(SparqlAndResult& _return, const CommonInfo& info, const std::vector<std::vector<std::string> > & input);
  int32_t send_query(const CommonInfo& info, const std::vector<std::vector<std::string> > & input);
  void recv_query(SparqlAndResult& _return, const int32_t seqid);
  void queryWithNeg(SparqlAndResult& _return, const NegCommonInfo& negInfo, const std::string& sparql);
  int32_t send_queryWithNeg(const NegCommonInfo& negInfo, const std::string& sparql);
  void recv_queryWithNeg(SparqlAndResult& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif
