#ifndef SIGMOID_LAYER_H
#define SIGMOID_LAYER_H

#include "i_act_layer.h"

template<MatMode mode, typename Dtype>
class SigmoidLayer; 

template<typename Dtype>
class SigmoidLayer<CPU, Dtype> : public IActLayer<CPU, Dtype> 
{
public:
    SigmoidLayer(std::string _name, GraphAtt _at, WriteType _wt, PropErr _properr = PropErr::T)
            : IActLayer<CPU, Dtype>(_name, _at, _wt, _properr) {}            


    virtual void Act(DenseMat<CPU, Dtype>& prev_out, DenseMat<CPU, Dtype>& cur_out) override;
    
    virtual void Derivative(DenseMat<CPU, Dtype>& dst, DenseMat<CPU, Dtype>& prev_output, 
                            DenseMat<CPU, Dtype>& cur_output, DenseMat<CPU, Dtype>& cur_grad) override; 
};

template<typename Dtype>
class SigmoidLayer<GPU, Dtype> : public IActLayer<GPU, Dtype> 
{
public:
    SigmoidLayer(std::string _name, GraphAtt _at, WriteType _wt, PropErr _properr = PropErr::T)
            : IActLayer<GPU, Dtype>(_name, _at, _wt, _properr) {}    

    virtual void Act(DenseMat<GPU, Dtype>& prev_out, DenseMat<GPU, Dtype>& cur_out) override; 
    
    virtual void Derivative(DenseMat<GPU, Dtype>& dst, DenseMat<GPU, Dtype>& prev_output, 
                            DenseMat<GPU, Dtype>& cur_output, DenseMat<GPU, Dtype>& cur_grad) override; 
};


#endif