Torch reference
===
>Lumin Zhou, Mar 2016

This is a brief note of torch7 documentations.

---
## [torch.Tensor](https://github.com/torch/torch7/blob/master/doc/tensor.md)  

#### constructors
1. torch.Tensor()  
  returns an empty tensor  
2. torch.Tensor(tensor)  
  returns a new tensor but refers the same storage than the origin  
3. torch.Tensor(size1[, size2[, size3[, size4]]])  
  creates a tensor up to 4 dimensions  
4. torch.Tensor(sizes, [strides])  
  creates a tensor of any number of dimensions  
5. torch.Tensor(storage, [storageOffset, sizes, [strides]])  
  returns a tensor which uses the existing storage.  
6. torch.Tensor(storage, [storageOffset, size1[, ...[, sz4[, st4]]]])  
7. torch.Tensor(table)  
  constructs a tensor from lua table  

#### clone
1. [Tensor] clone()  
	returns a clone of tensor. memory is copied.  
2. [Tensor] contiguouts()  
	returns an tensor contiguous in memory.  
3. [Tensor or string] type(type)  
	describes tensor type when type is nil, but when type is a string,
	return a new tensor in specified type.  
4. [Tensor] typeAs(tensor)  
	shortcut to `type(tensor:type())`  
5. [boolean] isTensor(object)  
6. [Tensor] byte(), char(), short(), int(), long(), float(), double()  
	shortcut to type(xxx)  

#### size and structure
1. [number] nDimension()  
	how many dimensions does a tensor have  
2. [number] dim()  
	alias to nDimensions()  
3. [number] size(dim)  
	size of specified dim.  
4. [LongStorage] size()  
5. [LongStorage] #self  
	same as size()  
6. [number] stride(dim)  
	returns jump size in memory  
7. [LongStorage] stride()  
	returns jump size in each dimension, in memory  
8. [Storage] storage()  
	returns storage used to store tensor elements, a way of dumping tensors.  
9. [boolean] isContiguous()  
	whether a tensor is contiguous in memory  
10. [boolean] isSize(storage)  
11. [boolean] isSameSizeAs(tensor)  
12. [number] nElement()  
13. [number] storageOffset()  

#### querying elements
1. x\[2\]\[3\]  
2. x[\{2,3\}]  

#### referencing tensor to existing tensor or memory chunk
1. [self] set(tensor)  
	The Tensor is now going to "view" the same storage as the given tensor  
2. [boolean] isSetTo(tensor)  
3. [self] set(storage, [storageOffset, sizes, [strides]])  
4. [self] set(storage, [storageOffset, sz1 [, st1 ... [, sz4 [, st4]]]])  

#### copying and initializing
1. [self] copy(tensor)  
	Replace the elements of the Tensor by copying the elements of the given tensor  
2. [self] fill(value)  
	fill the tensor with the given value  
3. [self] zeor()  
	fill the tensor with zeros  

#### resizing
1. [self] resizeAs(tensor)  
2. [self] resize(sizes)  
3. [self] resize(sz1 [,sz2 [,sz3 [,sz4]]]])  

#### Extracting sub-tensors (Slicing operations)
1. [self] narrow(dim, index, size)  
2. [Tensor] sub(dim1s, dim1e ... [, dim4s [, dim4e]])  
3. [Tensor] select(dim, index)  
4. \[Tensor\] [{ dim1,dim2,... }] or [{ {dim1s,dim1e}, {dim2s,dim2e} }]  
5. [Tensor] index(dim, index)  
6. [Tensor] indexCopy(dim, index, tensor)  
7. [Tensor] indexAdd(dim, index, tensor)  
8. [Tensor] indexfill(dim, index, val)  
9. [Tensor] gather(dim, index)  
10. [Tensor] scatter(dim, index, src|val)  
11. [Tensor] maskedSelect(mask)  
12. [Tensor] maskedCopy(mask, tensor)  
13. [Tensor] maskedFill(mask, val)  

#### searching
1. [LongTensor] nonzero(tensor)  

#### expanding/replicating/squeezing tensors
1. [result] expand([result,] sizes)  
2. [result] expandAs([result,] tensor)  
3. [Tensor] repeatTensor([result,] sizes)  
4. [Tensor] squeeze([dim])  

#### Manipulating the tensor view
1. [result] view([result,] tensor, sizes)  
2. [result] viewAs([result,] tensor, template)  
3. [Tensor] transpose(dim1, dim2)  
4. [Tensor] t()  
	shortcut transpose for 2D tensors  
5. [Tensor] permute(dim1, dim2, ..., dimn)  
6. [Tensor] unfold(dim, size, step)  

#### Applying a function to a tensor
1. [self] apply(function)  
2. [self] map(tensor, function(xs, xt))   
3. [self] map2(tensor1, tensor2, function(x, xt1, xt2))  

#### Dividing a tensor into a table of tensors
1. [result] split([result,] tensor, size, [dim])  
2. [result] chunk([result,] tensor, n, [dim])  

#### LuaJIT FFI access
1. [result] data(tensor, [asnumber])  
2. [result] cdata(tensor, [asnumber])  

#### Reference counting
1. retain()  
2. free()  

---

## [torch Math operations](./https://github.com/torch/torch7/blob/master/doc/maths.md)  

#### construction and extraction
1. [res] torch.cat([res,] x1, x2, [dimension])  
2. [res] torch.cat([res,] {x1, x2, ...}, [dimension])  
3. [res] torch.diag([res,] x [,k])  
4. [res] torch.eye([res,], n [, m])  
5. [res] torch.histc([res,] x [,nbins, min_value, max_value])  
6. [res] torch.linspace([res,] x1, x2, [,n])  
7. [res] torch.logspace([res,] x1, x2, [,n])  
8. [res] torch.multinomial([res,], p, n, [,replacement])  
9. [res] torch.ones([res,] m [,n...])  
10. [res] torch.rand([res,] m [,n...])  
11. [res] torch.randn([res,] m [,n...])  
12. [res] torch.range([res,] x, y [,step])
13. [res] torch.randperm([res,] n)  
14. [res] torch.reshape([res,] x, m [,n...])  
15. [res] torch.tril([res,] x [,k])  
16. [res] torch.triu([res,] x, [,k])  
17. [res] torch.zeros([res,] x)  

#### Element-wise Mathematical Operations
1. [res] torch.abs([res,] x)  
2. [res] torch.sign([res,] x)  
3. [res] torch.acos([res,] x)  
4. [res] torch.asin([res,] x)  
5. [res] torch.atan([res,] x)  
6. [res] torch.ceil([res,] x)  
7. [res] torch.cos([res,] x)  
8. [res] torch.cosh([res,] x)  
9. [res] torch.exp([res,] x)  
10. [res] torch.floor([res,] x)  
11. [res] torch.log([res,] x)  
12. [res] torch.log1p([res,] x)  
13. x:neg()  
14. x:cinv()  
15. [res] torch.pow([res,] x, n)  
16. [res] torch.round([res,] x)  
17. [res] torch.sin([res,] x)  
18. [res] torch.sinh([res,] x)  
19. [res] torch.sqrt([res,] x)  
20. [res] torch.tan([res,] x)  
21. [res] torch.tanh([res,] x)  
22. [res] torch.sigmoid([res,] x)  

#### Basic Operations
1. [res] torch.add([res,] tensor, value)  
2. [res] torch.add([res,] tensor1, tensor2)  
3. [res] torch.add([res,] tensor1, value, tensor2)  
4. tensor:csub(value)  
5. tensor1:csub(tensor2)  
6. [res] torch.mul([res,] tensor1, value)  
7. [res] torch.clamp([res,] tensor, min_value, max_value)  
	Clamp all elements in the Tensor into the range [min_value, max_value]  
8. [res] torch.cmul([res,] tensor1, tensor2)  
9. [res] torch.cpow([res,] tensor1, tensor2)  
10. [res] torch.addcmul([res,] x [,value], tensor1, tensor2)  
11. [res] torch.div([res,] tensor, value)  
12. [res] torch.cdiv([res,] tensor1, tensor2)  
13. [res] torch.addcdiv([res,] x [,value], tensor1, tensor2)  
14. [res] torch.mod([res,] tensor, value)  
15. [res] torch.cmod([res,] tensor1, tensor2)  
16. [number] torch.dot(tensor1, tensor2)  
17. [res] torch.addmv([res,] [beta,] [v1,] vec1, [v2,] mat, vec2)  
18. [res] torch.addr([res,] [v1,] mat, [v2,] vec1, vec2)  
19. [res] torch.addmm([res,] [beta,] [v1,] M [v2,] mat1, mat2)  
20. [res] torch.addbmm([res,] [v1,] M [v2,] batch1, batch2)  
21. [res] torch.baddbmm([res,] [v1,] M [v2,] batch1, batch2)  
22. [res] torch.mv([res,] mat, vec)  
23. [res] torch.mm([res,] mat1, mat2)  
24. [res] torch.bmm([res,] batch1, batch2)  
25. [res] torch.ger([res,] vec1, vec2)  

#### Overloaded operators
+placeholder

#### Column or row-wise operations (dimension-wise operations)
1. [res] torch.cross([res,] a, b [,n])  
2. [res] torch.cumprod([res,] x [,dim])  
3. [res] torch.cumsum([res,] x [,dim])  
4. torch.max([resval, resind,] x [,dim])  
5. [res] torch.mean([res,] x [,dim])  
6. torch.min([resval, resind,] x [,dim])  
7. [res] torch.cmax([res,] tensor1, tensor2)  
8. [res] torch.cmax([res,] tensor, value)  
9. [res] torch.cmin([res,] tensor1, tensor2)  
10. [res] torch.cmin([res,] tensor, value)  
11. torch.median([resval, resind,] x [,dim])  
12. torch.mode([resval, resind,] x [,dim])  
13. torch.kthvalue([resval, resind,] x, k [,dim])  
14. [res] torch.prod([res,] x [,n])  
15. torch.sort([resval, resind,] x [,d] [,flag])  
16. torch.topk([resval, resind,] x, k, [,dim] [,dir] [,sort])  
17. [res] torch.std([res,] x, [,dim] [,flag])  
18. [res] torch.sum([res,] x)  
19. [res] torch.var([res,] x [,dim] [,flag])  

#### Matrix-wide operations (Tensor-wide operations)
1. torch.norm(x [,p] [,dim])  
2. torch.renorm([res], x, p, dim, maxnorm)  
3. torch.dist(x, y)  
4. torch.numel(x)  
5. torch.trace(x)  

#### Convolution Operations
1. [res] torch.conv2([res,] x, k, [, 'F' or 'V'])  
2. [res] torch.xcorr2([res,] x, k, [, 'F' or 'V'])  
3. [res] torch.conv3([res,] x, k, [, 'F' or 'V'])
4. [res] torch.xcorr3([res,] x, k, [, 'F' or 'V'])  

#### Eigenvalues, SVD, Linear System Solution
1. [x, lu] torch.gesv([resb, resa,] B, A)  
2. [x] torch.trtrs([resb, resa,] b, a [, 'U' or 'L'] [, 'N' or 'T'] [, 'N' or 'U'])  
3. torch.potrf([res,] A [, 'U' or 'L'] )  
4. torch.pstrf([res, piv, ] A [, 'U' or 'L'] )  
5. torch.potrs([res,] B, chol [, 'U' or 'L'] )  
6. torch.potri([res,] chol [, 'U' or 'L'] )  
7. torch.gels([resb, resa,] b, a)  
8. torch.symeig([rese, resv,] a [, 'N' or 'V'] [, 'U' or 'L'])  
9. torch.eig([rese, resv,] a [, 'N' or 'V'])  
10. torch.svd([resu, ress, resv,] a [, 'S' or 'A'])  
11. torch.inverse([res,] x)  
12. torch.qr([q, r], x)  
13. torch.geqrf([m, tau], a)  
14. torch.orgqr([q], m, tau)  
15. torch.ormqr([res], m, tau, mat [, 'L' or 'R'] [, 'N' or 'T'])  

#### Logical Operations on Tensors
1. torch.lt(a, b)  
2. torch.le(a, b)  
3. torch.gt(a, b)  
4. torch.ge(a, b)  
5. torch.eq(a, b)  
6. torch.ne(a, b)  
7. torch.all(a)  
8. torch.any(a)  

---  
## [nn.Module](https://github.com/torch/nn/blob/master/doc/module.md)  

#### methods
1. [output] forward(input)  
  It is not advised to override this function.
	Instead, one should implement updateOutput(input) function.  
2. [gradinput] backward(input, gradOutput)  
  It is not advised to override this function call in custom classes.
 	It is better to override updateGradInput(input, gradOutput)
 	and accGradParameters(input, gradOutput,scale) functions.  
3. updateOutput(input)  
4. updateGradInput(input, gradOutput)  
5. accGradParameters(input, gradOutput, scale)  
  Zeroing this accumulation is achieved with zeroGradParameters()
 	and updating the parameters according to this accumulation is
 	done with updateParameters().  
5. zeroGradParameters()  
6. updateParameters(learningRate)  
  parameters = parameters - learningRate * gradients_wrt_parameters  
7. accUpdateGradParameters(input, gradOutput, learningRate)  
8. share(mlp, s1, s2, ..., sn)  
  shares parameters with specified modules.  
9. clone(mlp, ...)  
  creates deep copy of specified modules.  
10. type(type[, tensorCache])  
  converts all the parameters of a module to the specified type (torch.Tensor).  
11. float()  
  shortcut to module:type('torch.FloatTensor')  
12. double()  
  shortcut to module:type('torch.DoubleTensor')  
13. cuda()  
  shortcut to module:type('torch.CudaTensor')  
14. training()  
  toggles training mode for a module  
15. evaluate()  
  toggles evaluation mode for a module  
16. findModules(typename)  
17. listModules()  
18. clearState()  
  clears intermediate modules states as output, gradInput and others.  

#### variables
1. output  
  results of forward(input) will be put here  
2. gradinput  
  results of updateGradInput(input, gradOutput) will be put here  
3. [{weights}, {gradWeights}] parameters()  
4. [flatParameters, flatGradParameters] getParameters()  
