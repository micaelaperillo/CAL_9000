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

Token ArithmeticOperatorLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);
Token IntegerLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);
Token ParenthesisLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token UnknownLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token CheckLexemeAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token AutomataFunctionAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token ColonPatternAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token CommaPatternAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token SemicolonPatternAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token EndAutomataFunctionAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token RuleFunctionAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token EndRuleFunctionAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token ColorSetupAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token ColorHandlerAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token BgColorSetupAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token WrappingSetupAction(LexicalAnalyzerContext *lexicalAnalyzerContext);

Token TruePatternAction(LexicalAnalyzerContext * lexicalAnalyzerContext);
Token FalsePatternAction(LexicalAnalyzerContext * lexicalAnalyzerContext);

#endif