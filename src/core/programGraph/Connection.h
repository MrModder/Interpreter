#pragma once
#pragma once
#include <cstddef>
#include <memory>
#include <programGraph/Datatype.h>
#include <visitors/Visitor.h>

class Block;

class Connection {
public:
    Connection();
    Connection(const std::shared_ptr<Block>& block, size_t output);
    virtual ~Connection();

    bool isConnected() const;
    std::shared_ptr<Block> connectedBlock() const;
    size_t connectedOutput();
    Datatype connectedType();

    MAKE_VISITABLE;

protected:
    std::weak_ptr<Block> m_block;
    size_t m_output {};

private:
};
