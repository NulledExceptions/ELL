////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     UnaryOperationNode.h (features)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Node.h"
#include "ModelGraph.h"
#include "ModelTransformer.h"

// stl
#include <string>

namespace nodes
{
    template <typename ValueType>
    class UnaryOperationNode : public model::Node
    {
    public:
        /// <summary> Constructor </summary>
        /// <param name="input"> The signal to take the mean of </param>
        UnaryOperationNode(const model::OutputPortElementList<ValueType>& input);
        
        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        static std::string GetTypeName() { return "UnaryOperationNode"; }

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        virtual std::string GetRuntimeTypeName() const override { return GetTypeName(); }

        /// <summary> Exposes the output port as a read-only property </summary>
        const model::OutputPort<ValueType>& output = _output;

        virtual void Copy(model::ModelTransformer& transformer) const override;

    protected:
        virtual void Compute() const override;

    private:
        // Inputs
        model::InputPort<ValueType> _input;

        // Output
        model::OutputPort<ValueType> _output;
    };
}

#include "../tcc/UnaryOperationNode.tcc"