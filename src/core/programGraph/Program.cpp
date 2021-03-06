#include <error/InternalError.h>
#include <programGraph/Program.h>
#include <utility>
#include <visitors/RecursiveExecutor.h>

Program::Program(GraphicalFunction::UPtr startFunction, std::vector<GraphicalFunction::UPtr> functions)
{
    if (startFunction == nullptr) {
        THROW_ERROR(InternalError, "Program created with no starting function!");
    }
    m_startFunction = std::move(startFunction);
    m_functions = std::move(functions);
}

Program::Program(Program&& other)
{
    m_startFunction = std::move(other.m_startFunction);
    m_functions = std::move(other.m_functions);
}

std::vector<Value> Program::run(std::vector<Value> parameters)
{
    auto executor = RecursiveExecutor();
    return executor.evaluate(*m_startFunction, std::move(parameters));
}

std::vector<GraphicalFunction::UPtr>& Program::functions()
{
    return m_functions;
}

GraphicalFunction::UPtr& Program::startFunction()
{
    return m_startFunction;
}
