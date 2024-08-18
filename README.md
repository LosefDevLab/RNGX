# RNGX
##### A random number generator that uses exponentiation-tree and pseudo-random enhancement levels to generate highly pseudo-random numbers.
##### (x,y,z) "x" represents the number of top-level RNGs, "y" represents the number of enhancement levels, and "z" represents the number of RNGs contained within each enhancement level.
### Principle
##### The top layer consists of the few RNGs that ultimately output the final random numbers, with the enhancement levels below them.
##### Each of the x RNGs in the top layer has y RNGs below it, providing the random numbers (seeds) necessary for their generation. Each of these y RNGs, in turn, has y RNGs beneath them, also supplying random numbers (seeds). There are a total of z * y RNGs. When you do the z * y / z, you get a single enhancement level. The value of z represents the number of enhancement levels.
##### First, the x RNGs at the top layer send requests to the RNGs in the enhancement levels below them, asking them to generate random numbers as seeds. The RNGs below, in turn, send the same request to the RNGs in the next enhancement level down, continuing this process until it reaches the bottom layer. The bottom layer then generates random numbers that are passed up through the layers, eventually reaching the top x RNGs, which then combine to produce the final random number.
##### Thus, the computational complexity of RNGX is x*(y^z)
> [!Note]
> It requires a large amount of memory, especially for larger models. Models with (..., ..., 30) or fewer parameters can run on small PC or office computers (16GB RAM). Models with (..., ..., 300 or 3000) parameters can run on high-memory  or small to medium-sized servers. Models with (..., ..., 30000 or 300000) parameters are suitable for large servers or supercomputers.
