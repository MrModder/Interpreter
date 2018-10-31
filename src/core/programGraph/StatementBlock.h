#pragma once
#include <programGraph/Block.h>
#include <programGraph/ProgramFlowConnection.h>
#include <memory>

class StatementBlock : public Block
{
public:
	using Ptr = std::shared_ptr<StatementBlock>;

	virtual ~StatementBlock();
	size_t flowConnectionsCount();

	const std::vector<ProgramFlowConnection>& flowConnections();
	void setFlowConnections(const std::vector<ProgramFlowConnection>& connections);
	void setFlowConnection(size_t index, const ProgramFlowConnection& connection);

protected:
	StatementBlock(size_t inputCount, size_t flowConnectionsCount = 1);

	std::vector<ProgramFlowConnection> m_flowConnections;
private:
};