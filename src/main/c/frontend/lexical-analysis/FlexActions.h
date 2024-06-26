#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../shared/Environment.h"
#include "../../shared/Logger.h"
#include "../../shared/String.h"
#include "../../shared/Type.h"
#include "../syntactic-analysis/AbstractSyntaxTree.h"
#include "../syntactic-analysis/BisonParser.h"
#include "LexicalAnalyzerContext.h"
#include <stdio.h>
#include <stdlib.h>

/** Initialize module's internal state. */
void initializeFlexActionsModule();

/** Shutdown module's internal state. */
void shutdownFlexActionsModule();

/**
 * Flex lexeme processing actions.
 */

void BeginMultilineCommentLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);
void EndMultilineCommentLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);
void IgnoredLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token IntegerLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);
Token OpenParenthesisLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);
Token CloseParenthesisLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token UnknownLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token CheckLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token AutomataFunctionAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token ColonPatternAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token CommaPatternAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token SemicolonPatternAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token EqualPatternAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token EndAutomataFunctionAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token RuleFunctionAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token EndRuleFunctionAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token PropertyPatternAction(LexicalAnalyzerContext * lexicalAnalyzerContext);

Token ColorHandlerAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token TrueValuePatternAction(LexicalAnalyzerContext * lexicalAnalyzerContext);
Token FalseValuePatternAction(LexicalAnalyzerContext * lexicalAnalyzerContext);

Token GridSpecificationAction(LexicalAnalyzerContext * lexicalAnalyzerContext);

Token KeywordPatternAction(LexicalAnalyzerContext * lexicalAnalyzerContext);

#endif
