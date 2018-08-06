#pragma once

#include <programGraph/StatementBlock.h>
#include <programGraph/GraphicalFunction.h>
#include <visitors/Visitor.h>

class VariableWriteBlock : public StatementBlock
{
public:
	VariableWriteBlock(class GraphicalFunction& owningFunction, VariableIdentifier identifier);
	virtual ~VariableWriteBlock() = default;

	MAKE_VISITABLE;

	virtual std::vector<Datatype> inputTypes() const override;
	virtual std::vector<Datatype> outputTypes() const override;

protected:
	
	class GraphicalFunction& m_owningFunction;
	VariableIdentifier m_identifier;
private:
};