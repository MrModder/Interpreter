#include <programGraph/GraphicalFunction.h>

GraphicalFunction::GraphicalFunction()
{}

GraphicalFunction::~GraphicalFunction()
{}

const std::vector<FunctionBlock::UPtr>& GraphicalFunction::functionBlocks()
{
	return m_functionBlocks;
}

void GraphicalFunction::setFunctionBlocks(std::vector<FunctionBlock::UPtr> blocks)
{
	m_functionBlocks = std::move(blocks);
}