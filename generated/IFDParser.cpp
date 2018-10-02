
// Generated from /Users/max/dev/shout/src/IFD.g4 by ANTLR 4.7.1


#include "IFDListener.h"
#include "IFDVisitor.h"

#include "IFDParser.h"


using namespace antlrcpp;
using namespace shout;
using namespace antlr4;

IFDParser::IFDParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

IFDParser::~IFDParser() {
  delete _interpreter;
}

std::string IFDParser::getGrammarFileName() const {
  return "IFD.g4";
}

const std::vector<std::string>& IFDParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& IFDParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

IFDParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IFDParser::LineContext *> IFDParser::FileContext::line() {
  return getRuleContexts<IFDParser::LineContext>();
}

IFDParser::LineContext* IFDParser::FileContext::line(size_t i) {
  return getRuleContext<IFDParser::LineContext>(i);
}


size_t IFDParser::FileContext::getRuleIndex() const {
  return IFDParser::RuleFile;
}

void IFDParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void IFDParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


antlrcpp::Any IFDParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::FileContext* IFDParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, IFDParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << IFDParser::T__0)
      | (1ULL << IFDParser::T__2)
      | (1ULL << IFDParser::T__3)
      | (1ULL << IFDParser::T__4)
      | (1ULL << IFDParser::T__5)
      | (1ULL << IFDParser::T__6)
      | (1ULL << IFDParser::T__10)
      | (1ULL << IFDParser::T__11)
      | (1ULL << IFDParser::T__12)
      | (1ULL << IFDParser::T__13)
      | (1ULL << IFDParser::T__14)
      | (1ULL << IFDParser::T__15)
      | (1ULL << IFDParser::COMMENT))) != 0)) {
      setState(28);
      line();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

IFDParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IFDParser::VersionContext* IFDParser::LineContext::version() {
  return getRuleContext<IFDParser::VersionContext>(0);
}

IFDParser::DeclareContext* IFDParser::LineContext::declare() {
  return getRuleContext<IFDParser::DeclareContext>(0);
}

IFDParser::SetenvContext* IFDParser::LineContext::setenv() {
  return getRuleContext<IFDParser::SetenvContext>(0);
}

IFDParser::StartContext* IFDParser::LineContext::start() {
  return getRuleContext<IFDParser::StartContext>(0);
}

IFDParser::EndContext* IFDParser::LineContext::end() {
  return getRuleContext<IFDParser::EndContext>(0);
}

IFDParser::DetailContext* IFDParser::LineContext::detail() {
  return getRuleContext<IFDParser::DetailContext>(0);
}

IFDParser::PropertyContext* IFDParser::LineContext::property() {
  return getRuleContext<IFDParser::PropertyContext>(0);
}

IFDParser::ImageContext* IFDParser::LineContext::image() {
  return getRuleContext<IFDParser::ImageContext>(0);
}

IFDParser::GeomertyContext* IFDParser::LineContext::geomerty() {
  return getRuleContext<IFDParser::GeomertyContext>(0);
}

IFDParser::TimeContext* IFDParser::LineContext::time() {
  return getRuleContext<IFDParser::TimeContext>(0);
}

IFDParser::RaytraceContext* IFDParser::LineContext::raytrace() {
  return getRuleContext<IFDParser::RaytraceContext>(0);
}

IFDParser::QuitContext* IFDParser::LineContext::quit() {
  return getRuleContext<IFDParser::QuitContext>(0);
}

tree::TerminalNode* IFDParser::LineContext::COMMENT() {
  return getToken(IFDParser::COMMENT, 0);
}


size_t IFDParser::LineContext::getRuleIndex() const {
  return IFDParser::RuleLine;
}

void IFDParser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void IFDParser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}


antlrcpp::Any IFDParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::LineContext* IFDParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, IFDParser::RuleLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IFDParser::T__2: {
        enterOuterAlt(_localctx, 1);
        setState(34);
        version();
        break;
      }

      case IFDParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(35);
        declare();
        break;
      }

      case IFDParser::T__0: {
        enterOuterAlt(_localctx, 3);
        setState(36);
        setenv();
        break;
      }

      case IFDParser::T__4: {
        enterOuterAlt(_localctx, 4);
        setState(37);
        start();
        break;
      }

      case IFDParser::T__5: {
        enterOuterAlt(_localctx, 5);
        setState(38);
        end();
        break;
      }

      case IFDParser::T__6: {
        enterOuterAlt(_localctx, 6);
        setState(39);
        detail();
        break;
      }

      case IFDParser::T__10: {
        enterOuterAlt(_localctx, 7);
        setState(40);
        property();
        break;
      }

      case IFDParser::T__11: {
        enterOuterAlt(_localctx, 8);
        setState(41);
        image();
        break;
      }

      case IFDParser::T__12: {
        enterOuterAlt(_localctx, 9);
        setState(42);
        geomerty();
        break;
      }

      case IFDParser::T__13: {
        enterOuterAlt(_localctx, 10);
        setState(43);
        time();
        break;
      }

      case IFDParser::T__14: {
        enterOuterAlt(_localctx, 11);
        setState(44);
        raytrace();
        break;
      }

      case IFDParser::T__15: {
        enterOuterAlt(_localctx, 12);
        setState(45);
        quit();
        break;
      }

      case IFDParser::COMMENT: {
        enterOuterAlt(_localctx, 13);
        setState(46);
        match(IFDParser::COMMENT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetenvContext ------------------------------------------------------------------

IFDParser::SetenvContext::SetenvContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::SetenvContext::VAR_NAME() {
  return getToken(IFDParser::VAR_NAME, 0);
}

tree::TerminalNode* IFDParser::SetenvContext::VALUE() {
  return getToken(IFDParser::VALUE, 0);
}


size_t IFDParser::SetenvContext::getRuleIndex() const {
  return IFDParser::RuleSetenv;
}

void IFDParser::SetenvContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetenv(this);
}

void IFDParser::SetenvContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetenv(this);
}


antlrcpp::Any IFDParser::SetenvContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitSetenv(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::SetenvContext* IFDParser::setenv() {
  SetenvContext *_localctx = _tracker.createInstance<SetenvContext>(_ctx, getState());
  enterRule(_localctx, 4, IFDParser::RuleSetenv);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(IFDParser::T__0);
    setState(50);
    match(IFDParser::VAR_NAME);
    setState(51);
    match(IFDParser::T__1);
    setState(52);
    match(IFDParser::VALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionContext ------------------------------------------------------------------

IFDParser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::VersionContext::VERSION() {
  return getToken(IFDParser::VERSION, 0);
}


size_t IFDParser::VersionContext::getRuleIndex() const {
  return IFDParser::RuleVersion;
}

void IFDParser::VersionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersion(this);
}

void IFDParser::VersionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersion(this);
}


antlrcpp::Any IFDParser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::VersionContext* IFDParser::version() {
  VersionContext *_localctx = _tracker.createInstance<VersionContext>(_ctx, getState());
  enterRule(_localctx, 6, IFDParser::RuleVersion);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(IFDParser::T__2);
    setState(55);
    match(IFDParser::VERSION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareContext ------------------------------------------------------------------

IFDParser::DeclareContext::DeclareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::DeclareContext::OBJECT() {
  return getToken(IFDParser::OBJECT, 0);
}

tree::TerminalNode* IFDParser::DeclareContext::TYPE() {
  return getToken(IFDParser::TYPE, 0);
}

tree::TerminalNode* IFDParser::DeclareContext::VAR_NAME() {
  return getToken(IFDParser::VAR_NAME, 0);
}

tree::TerminalNode* IFDParser::DeclareContext::VALUE() {
  return getToken(IFDParser::VALUE, 0);
}


size_t IFDParser::DeclareContext::getRuleIndex() const {
  return IFDParser::RuleDeclare;
}

void IFDParser::DeclareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclare(this);
}

void IFDParser::DeclareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclare(this);
}


antlrcpp::Any IFDParser::DeclareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitDeclare(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::DeclareContext* IFDParser::declare() {
  DeclareContext *_localctx = _tracker.createInstance<DeclareContext>(_ctx, getState());
  enterRule(_localctx, 8, IFDParser::RuleDeclare);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(IFDParser::T__3);
    setState(58);
    match(IFDParser::OBJECT);
    setState(59);
    match(IFDParser::TYPE);
    setState(60);
    match(IFDParser::VAR_NAME);
    setState(61);
    match(IFDParser::VALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartContext ------------------------------------------------------------------

IFDParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::StartContext::OBJECT() {
  return getToken(IFDParser::OBJECT, 0);
}


size_t IFDParser::StartContext::getRuleIndex() const {
  return IFDParser::RuleStart;
}

void IFDParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void IFDParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


antlrcpp::Any IFDParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::StartContext* IFDParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 10, IFDParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(IFDParser::T__4);
    setState(64);
    match(IFDParser::OBJECT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndContext ------------------------------------------------------------------

IFDParser::EndContext::EndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t IFDParser::EndContext::getRuleIndex() const {
  return IFDParser::RuleEnd;
}

void IFDParser::EndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnd(this);
}

void IFDParser::EndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnd(this);
}


antlrcpp::Any IFDParser::EndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitEnd(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::EndContext* IFDParser::end() {
  EndContext *_localctx = _tracker.createInstance<EndContext>(_ctx, getState());
  enterRule(_localctx, 12, IFDParser::RuleEnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(IFDParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DetailContext ------------------------------------------------------------------

IFDParser::DetailContext::DetailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::DetailContext::VAR_NAME() {
  return getToken(IFDParser::VAR_NAME, 0);
}

tree::TerminalNode* IFDParser::DetailContext::STRING() {
  return getToken(IFDParser::STRING, 0);
}

std::vector<tree::TerminalNode *> IFDParser::DetailContext::VALUE() {
  return getTokens(IFDParser::VALUE);
}

tree::TerminalNode* IFDParser::DetailContext::VALUE(size_t i) {
  return getToken(IFDParser::VALUE, i);
}

tree::TerminalNode* IFDParser::DetailContext::STREAM() {
  return getToken(IFDParser::STREAM, 0);
}


size_t IFDParser::DetailContext::getRuleIndex() const {
  return IFDParser::RuleDetail;
}

void IFDParser::DetailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDetail(this);
}

void IFDParser::DetailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDetail(this);
}


antlrcpp::Any IFDParser::DetailContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitDetail(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::DetailContext* IFDParser::detail() {
  DetailContext *_localctx = _tracker.createInstance<DetailContext>(_ctx, getState());
  enterRule(_localctx, 14, IFDParser::RuleDetail);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(IFDParser::T__6);
    setState(75);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IFDParser::T__7: {
        setState(69);
        match(IFDParser::T__7);
        break;
      }

      case IFDParser::T__8: {
        setState(70);
        match(IFDParser::T__8);
        setState(71);
        match(IFDParser::VALUE);
        break;
      }

      case IFDParser::T__9: {
        setState(72);
        match(IFDParser::T__9);
        setState(73);
        match(IFDParser::VALUE);
        setState(74);
        match(IFDParser::VALUE);
        break;
      }

      case IFDParser::VAR_NAME:
      case IFDParser::VALUE:
      case IFDParser::STRING: {
        break;
      }

    default:
      break;
    }
    setState(77);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << IFDParser::VAR_NAME)
      | (1ULL << IFDParser::VALUE)
      | (1ULL << IFDParser::STRING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(78);
    _la = _input->LA(1);
    if (!(_la == IFDParser::STREAM

    || _la == IFDParser::VALUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyContext ------------------------------------------------------------------

IFDParser::PropertyContext::PropertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::PropertyContext::OBJECT() {
  return getToken(IFDParser::OBJECT, 0);
}

tree::TerminalNode* IFDParser::PropertyContext::VAR_NAME() {
  return getToken(IFDParser::VAR_NAME, 0);
}

tree::TerminalNode* IFDParser::PropertyContext::STREAM() {
  return getToken(IFDParser::STREAM, 0);
}

tree::TerminalNode* IFDParser::PropertyContext::VALUE() {
  return getToken(IFDParser::VALUE, 0);
}


size_t IFDParser::PropertyContext::getRuleIndex() const {
  return IFDParser::RuleProperty;
}

void IFDParser::PropertyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty(this);
}

void IFDParser::PropertyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty(this);
}


antlrcpp::Any IFDParser::PropertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitProperty(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::PropertyContext* IFDParser::property() {
  PropertyContext *_localctx = _tracker.createInstance<PropertyContext>(_ctx, getState());
  enterRule(_localctx, 16, IFDParser::RuleProperty);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(IFDParser::T__10);
    setState(81);
    match(IFDParser::OBJECT);
    setState(82);
    match(IFDParser::VAR_NAME);
    setState(83);
    _la = _input->LA(1);
    if (!(_la == IFDParser::STREAM

    || _la == IFDParser::VALUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImageContext ------------------------------------------------------------------

IFDParser::ImageContext::ImageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> IFDParser::ImageContext::VALUE() {
  return getTokens(IFDParser::VALUE);
}

tree::TerminalNode* IFDParser::ImageContext::VALUE(size_t i) {
  return getToken(IFDParser::VALUE, i);
}


size_t IFDParser::ImageContext::getRuleIndex() const {
  return IFDParser::RuleImage;
}

void IFDParser::ImageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImage(this);
}

void IFDParser::ImageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImage(this);
}


antlrcpp::Any IFDParser::ImageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitImage(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::ImageContext* IFDParser::image() {
  ImageContext *_localctx = _tracker.createInstance<ImageContext>(_ctx, getState());
  enterRule(_localctx, 18, IFDParser::RuleImage);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(IFDParser::T__11);
    setState(86);
    match(IFDParser::VALUE);
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == IFDParser::VALUE) {
      setState(87);
      match(IFDParser::VALUE);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GeomertyContext ------------------------------------------------------------------

IFDParser::GeomertyContext::GeomertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::GeomertyContext::VALUE() {
  return getToken(IFDParser::VALUE, 0);
}


size_t IFDParser::GeomertyContext::getRuleIndex() const {
  return IFDParser::RuleGeomerty;
}

void IFDParser::GeomertyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeomerty(this);
}

void IFDParser::GeomertyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeomerty(this);
}


antlrcpp::Any IFDParser::GeomertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitGeomerty(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::GeomertyContext* IFDParser::geomerty() {
  GeomertyContext *_localctx = _tracker.createInstance<GeomertyContext>(_ctx, getState());
  enterRule(_localctx, 20, IFDParser::RuleGeomerty);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(IFDParser::T__12);
    setState(91);
    match(IFDParser::VALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeContext ------------------------------------------------------------------

IFDParser::TimeContext::TimeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::TimeContext::VALUE() {
  return getToken(IFDParser::VALUE, 0);
}


size_t IFDParser::TimeContext::getRuleIndex() const {
  return IFDParser::RuleTime;
}

void IFDParser::TimeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTime(this);
}

void IFDParser::TimeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTime(this);
}


antlrcpp::Any IFDParser::TimeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitTime(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::TimeContext* IFDParser::time() {
  TimeContext *_localctx = _tracker.createInstance<TimeContext>(_ctx, getState());
  enterRule(_localctx, 22, IFDParser::RuleTime);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(IFDParser::T__13);
    setState(94);
    match(IFDParser::VALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RaytraceContext ------------------------------------------------------------------

IFDParser::RaytraceContext::RaytraceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t IFDParser::RaytraceContext::getRuleIndex() const {
  return IFDParser::RuleRaytrace;
}

void IFDParser::RaytraceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRaytrace(this);
}

void IFDParser::RaytraceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRaytrace(this);
}


antlrcpp::Any IFDParser::RaytraceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitRaytrace(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::RaytraceContext* IFDParser::raytrace() {
  RaytraceContext *_localctx = _tracker.createInstance<RaytraceContext>(_ctx, getState());
  enterRule(_localctx, 24, IFDParser::RuleRaytrace);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(IFDParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuitContext ------------------------------------------------------------------

IFDParser::QuitContext::QuitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t IFDParser::QuitContext::getRuleIndex() const {
  return IFDParser::RuleQuit;
}

void IFDParser::QuitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuit(this);
}

void IFDParser::QuitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuit(this);
}


antlrcpp::Any IFDParser::QuitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitQuit(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::QuitContext* IFDParser::quit() {
  QuitContext *_localctx = _tracker.createInstance<QuitContext>(_ctx, getState());
  enterRule(_localctx, 26, IFDParser::RuleQuit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    match(IFDParser::T__15);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> IFDParser::_decisionToDFA;
atn::PredictionContextCache IFDParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN IFDParser::_atn;
std::vector<uint16_t> IFDParser::_serializedATN;

std::vector<std::string> IFDParser::_ruleNames = {
  "file", "line", "setenv", "version", "declare", "start", "end", "detail", 
  "property", "image", "geomerty", "time", "raytrace", "quit"
};

std::vector<std::string> IFDParser::_literalNames = {
  "", "'setenv'", "'='", "'ray_version'", "'ray_declare'", "'ray_start'", 
  "'ray_end'", "'ray_detail'", "'-T'", "'-v'", "'-V'", "'ray_property'", 
  "'ray_image'", "'ray_geometry'", "'ray_time'", "'ray_raytrace'", "'ray_quit'"
};

std::vector<std::string> IFDParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "COMMENT", 
  "STREAM", "TYPE", "OBJECT", "VERSION", "VAR_NAME", "VALUE", "INTEGER", 
  "NUMBER", "STRING", "NO_QUOTED", "QUOTED", "CHARS", "WS"
};

dfa::Vocabulary IFDParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> IFDParser::_tokenNames;

IFDParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x20, 0x67, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x3, 0x2, 0x7, 0x2, 0x20, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x23, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x32, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0x4e, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0x5b, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x2, 0x2, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x2, 0x4, 0x4, 0x2, 0x18, 0x19, 0x1c, 0x1c, 
    0x4, 0x2, 0x14, 0x14, 0x19, 0x19, 0x2, 0x69, 0x2, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x31, 0x3, 0x2, 0x2, 0x2, 0x6, 0x33, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x44, 0x3, 0x2, 0x2, 0x2, 0x10, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x52, 0x3, 0x2, 0x2, 0x2, 0x14, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x18, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x62, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x64, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x20, 0x5, 0x4, 0x3, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x3, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x32, 0x5, 0x8, 0x5, 0x2, 0x25, 0x32, 0x5, 0xa, 
    0x6, 0x2, 0x26, 0x32, 0x5, 0x6, 0x4, 0x2, 0x27, 0x32, 0x5, 0xc, 0x7, 
    0x2, 0x28, 0x32, 0x5, 0xe, 0x8, 0x2, 0x29, 0x32, 0x5, 0x10, 0x9, 0x2, 
    0x2a, 0x32, 0x5, 0x12, 0xa, 0x2, 0x2b, 0x32, 0x5, 0x14, 0xb, 0x2, 0x2c, 
    0x32, 0x5, 0x16, 0xc, 0x2, 0x2d, 0x32, 0x5, 0x18, 0xd, 0x2, 0x2e, 0x32, 
    0x5, 0x1a, 0xe, 0x2, 0x2f, 0x32, 0x5, 0x1c, 0xf, 0x2, 0x30, 0x32, 0x7, 
    0x13, 0x2, 0x2, 0x31, 0x24, 0x3, 0x2, 0x2, 0x2, 0x31, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x26, 0x3, 0x2, 0x2, 0x2, 0x31, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x28, 0x3, 0x2, 0x2, 0x2, 0x31, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x31, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x31, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x30, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x5, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x3, 
    0x2, 0x2, 0x34, 0x35, 0x7, 0x18, 0x2, 0x2, 0x35, 0x36, 0x7, 0x4, 0x2, 
    0x2, 0x36, 0x37, 0x7, 0x19, 0x2, 0x2, 0x37, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x39, 0x7, 0x5, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x17, 0x2, 0x2, 0x3a, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x6, 0x2, 0x2, 0x3c, 0x3d, 
    0x7, 0x16, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x15, 0x2, 0x2, 0x3e, 0x3f, 0x7, 
    0x18, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x19, 0x2, 0x2, 0x40, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x42, 0x7, 0x7, 0x2, 0x2, 0x42, 0x43, 0x7, 0x16, 0x2, 
    0x2, 0x43, 0xd, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x8, 0x2, 0x2, 
    0x45, 0xf, 0x3, 0x2, 0x2, 0x2, 0x46, 0x4d, 0x7, 0x9, 0x2, 0x2, 0x47, 
    0x4e, 0x7, 0xa, 0x2, 0x2, 0x48, 0x49, 0x7, 0xb, 0x2, 0x2, 0x49, 0x4e, 
    0x7, 0x19, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0xc, 0x2, 0x2, 0x4b, 0x4c, 0x7, 
    0x19, 0x2, 0x2, 0x4c, 0x4e, 0x7, 0x19, 0x2, 0x2, 0x4d, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x50, 0x9, 0x2, 0x2, 0x2, 0x50, 0x51, 0x9, 0x3, 0x2, 0x2, 0x51, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0xd, 0x2, 0x2, 0x53, 0x54, 
    0x7, 0x16, 0x2, 0x2, 0x54, 0x55, 0x7, 0x18, 0x2, 0x2, 0x55, 0x56, 0x9, 
    0x3, 0x2, 0x2, 0x56, 0x13, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 0xe, 
    0x2, 0x2, 0x58, 0x5a, 0x7, 0x19, 0x2, 0x2, 0x59, 0x5b, 0x7, 0x19, 0x2, 
    0x2, 0x5a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x15, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0xf, 0x2, 0x2, 0x5d, 
    0x5e, 0x7, 0x19, 0x2, 0x2, 0x5e, 0x17, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 
    0x7, 0x10, 0x2, 0x2, 0x60, 0x61, 0x7, 0x19, 0x2, 0x2, 0x61, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x11, 0x2, 0x2, 0x63, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x65, 0x7, 0x12, 0x2, 0x2, 0x65, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x21, 0x31, 0x4d, 0x5a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

IFDParser::Initializer IFDParser::_init;
