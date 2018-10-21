#pragma once

#include <visitors/Visitor.h>
#include <visitors/Evaluator.h>
#include <vector>
#include <programGraph/Value.h>
#include <programGraph/GraphicalFunction.h>
#include <unordered_map>
#include <map>
#include <stack>

struct Return
{
	std::vector<Value> m_values;
};

struct StackFrame
{
	std::map<VariableIdentifier, Value> m_variables;
	std::vector<Value> m_parameters;
};

class Executor : public Visitor<void>
{
public:
	Executor();
	virtual ~Executor();

	virtual void visit(class GraphicalFunction& graphicalFunction) override;
	virtual void visit(class FunctionBlock& functionBlock) override;
	virtual void visit(class Connection& connection) override;
	virtual void visit(class ValueBlock& valueBlock) override;
	virtual void visit(class PrimitiveFunction& primitiveFunction) override;
	virtual void visit(class VariableReadBlock& variableReadBlock) override;
	virtual void visit(class ParameterAccessBlock& parameterAccess) override;

	virtual void visit(class ReturnBlock& returnBlock) override;
	virtual void visit(class ExpressionStatement& expressionStatement) override;
	virtual void visit(class VariableWriteBlock& variableWriteBlock) override;
	virtual void visit(class IfStatement& ifStatement) override;
	virtual void visit(class WhileStatement& whileStatement) override;
	
	bool executeNext(class StatementBlock& statement);
	bool executeNext(class StatementBlock& statement, size_t flowConnectionIndex);

	std::vector<Value> evaluate(class StatementBlock& statement);
	std::vector<Value> evaluate(class GraphicalFunction& graphicalFunction);
	std::vector<Value> evaluate(class GraphicalFunction& graphicalFunction, std::vector<Value> parameters);
	Value variableValue(VariableIdentifier identifier);
	std::vector<Value> parameters() const;
protected:
	Evaluator m_evaluator;
	std::unordered_map<class StatementBlock*, std::vector<Value>> m_executedStatements;
	std::stack<StackFrame, std::vector<StackFrame>> m_callStack;

	void throwExpressionError();
private:
};