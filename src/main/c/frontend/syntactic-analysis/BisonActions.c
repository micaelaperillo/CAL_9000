#include "BisonActions.h"

/* MODULE INTERNAL STATE */

static Logger * _logger = NULL;

void initializeBisonActionsModule() {
	_logger = createLogger("BisonActions");
}

void shutdownBisonActionsModule() {
	if (_logger != NULL) {
		destroyLogger(_logger);
	}
}

/** IMPORTED FUNCTIONS */

extern unsigned int flexCurrentContext(void);

/* PRIVATE FUNCTIONS */

static void _logSyntacticAnalyzerAction(const char * functionName);

/**
 * Logs a syntactic-analyzer action in DEBUGGING level.
 */
static void _logSyntacticAnalyzerAction(const char * functionName) {
	logDebugging(_logger, "%s", functionName);
}

/* PUBLIC FUNCTIONS */

Constant * IntegerConstantSemanticAction(const int value) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Constant * constant = calloc(1, sizeof(Constant));
	constant->value = value;
	return constant;
}

Data * DataSemanticAction(char * dataType, int value) {
    _logSyntacticAnalyzerAction(__FUNCTION__);
    Data * data = calloc(1, sizeof(Data));
    data->value = value;
    return data;
}

ParameterList * ParameterListSemanticAction(Data * data, ParameterList * next) {
    _logSyntacticAnalyzerAction(__FUNCTION__);
    ParameterList * parameterList = calloc(1, sizeof(ParameterList));
    parameterList->data = data;
    parameterList->next = next;
    return parameterList;
}

PropertyList * PropertyListSemanticAction(Property * property, PropertyList * next) {
    _logSyntacticAnalyzerAction(__FUNCTION__);
    PropertyList * propertyList = calloc(1, sizeof(PropertyList));
    propertyList->property = property;
    propertyList->next = next;
    return propertyList;
}

Expression * ArithmeticExpressionSemanticAction(Expression * leftExpression, Expression * rightExpression, ExpressionType type) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Expression * expression = calloc(1, sizeof(Expression));
	expression->leftExpression = leftExpression;
	expression->rightExpression = rightExpression;
	expression->type = type;
	return expression;
}

Expression * FactorExpressionSemanticAction(Factor * factor) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Expression * expression = calloc(1, sizeof(Expression));
	expression->factor = factor;
	expression->type = FACTOR;
	return expression;
}

Check * CheckSemanticAction(const int x,const int y) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Check * check = calloc(1, sizeof(Check));
	check->x=x;
	check->y=y;
	return check;
}

RuleNumber* RuleNumberSemanticAction(const int nAliveToSurvive, const int nAliveToDie, const int nAliveToBeBorn) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	RuleNumber * ruleNumber = calloc(1, sizeof(RuleNumber));
	ruleNumber->neighboursAliveToSurvive = nAliveToSurvive;
	ruleNumber->neighboursAliveToDie = nAliveToDie;
	ruleNumber->neighboursAliveToBeBorn = nAliveToBeBorn;
	return ruleNumber;
}

Grid * GridSemanticAction(const int width, const int height) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Grid * grid = calloc(1, sizeof(Grid));
	grid->width = width;
	grid->height = height;
	return grid;
}

Factor * ConstantFactorSemanticAction(Constant * constant) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Factor * factor = calloc(1, sizeof(Factor));
	factor->constant = constant;
	factor->type = CONSTANT;
	return factor;
}

Factor * ExpressionFactorSemanticAction(Expression * expression) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Factor * factor = calloc(1, sizeof(Factor));
	factor->expression = expression;
	factor->type = EXPRESSION;
	return factor;
}

CheckList * CheckListSemanticAction(Check * check, CheckList * next) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	CheckList * checkList = calloc(1, sizeof(CheckList));
	checkList->check = check;
	checkList->next = next;
	return checkList;
}

Check * CheckSemanticAction(const int x, const int y) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Check * check = calloc(1, sizeof(Check));
	check->x = x;
	check->y = y;
	return check;
}


Automata * AutomataSemanticAction(RuleNumber * ruleNumber, Grid * grid, Check * checks) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Automata * automata = calloc(1, sizeof(Automata));
	automata->ruleNumber = ruleNumber;
	automata->grid = grid;
	automata->checks = checks;
    return automata;
}

Rule * RuleSemanticAction(PropertyList * properties) {
    _logSyntacticAnalyzerAction(__FUNCTION__);
    Rule * rule = calloc(1, sizeof(Rule));
    rule->properties = properties;
    return rule;
}

Program * ExpressionProgramSemanticAction(CompilerState * compilerState, Expression * expression) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Program * program = calloc(1, sizeof(Program));
	program->expression = expression;
	compilerState->abstractSyntaxtTree = program;
	if (0 < flexCurrentContext()) {
		logError(_logger, "The final context is not the default (0): %d", flexCurrentContext());
		compilerState->succeed = false;
	}
	else {
		compilerState->succeed = true;
	}
	return program;
}
