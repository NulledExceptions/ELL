////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     AccumulatorNode.tcc (nodes)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "AccumulatorNode.h"

// utilities
#include "Exception.h"

// stl
#include <string>
#include <vector>

namespace nodes
{
    template <typename ValueType>
    AccumulatorNode<ValueType>::AccumulatorNode(const model::OutputPortElementList<ValueType>& input) : Node({&_input}, {&_output}), _input(this, input), _output(this, _input.Size())
    {
        auto dimension = input.Size();
        _accumulator = std::vector<ValueType>(dimension);
    }

    template <typename ValueType>
    void AccumulatorNode<ValueType>::Compute() const
    {
        for(size_t index = 0; index < _input.Size(); ++index)
        {
            _accumulator[index] += _input[index];
        }
        _output.SetOutput(_accumulator);
    };

    template <typename ValueType>
    void AccumulatorNode<ValueType>::Copy(model::ModelTransformer& transformer) const
    {
        auto newInput = transformer.TransformInputPort(_input);
        auto newNode = transformer.AddNode<AccumulatorNode<ValueType>>(newInput);
        transformer.MapOutputPort(output, newNode->output);
    }

    template <typename ValueType>
    void AccumulatorNode<ValueType>::Refine(model::ModelTransformer& transformer) const
    {
        auto newInput = transformer.TransformInputPort(_input);
        auto newNode = transformer.AddNode<AccumulatorNode<ValueType>>(newInput);
        transformer.MapOutputPort(output, newNode->output);
    }
    
}
