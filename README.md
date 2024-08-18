# RNGX
##### A random number generator that uses exponentiation-tree and pseudo-random enhancement levels to generate highly pseudo-random numbers.
##### (z,y)or version.version.version.version.y.z "x" represents top-level RNG, "z" represents the number of enhancement levels, and "y" represents the number of RNGs contained within each enhancement level.
### Principle
##### The top layer consists of the few RNG that ultimately output the final random numbers, with the enhancement levels below them.
##### Each of the x RNG at the top layer has y RNGs beneath them providing the seeds for generating random numbers. Similarly, each of these y RNGs also has y RNGs beneath them, which also provide seeds. In total, there are z groups of y RNGs. Dividing z*y by z gives the number of RNGs per enhancement level, and z represents the number of enhancement levels.
##### First, the top layer's x RNG issue requests for random numbers to be generated as seeds from the RNGs in the enhancement levels below them. Each RNG within an enhancement level similarly requests random numbers from the RNGs in the next lower enhancement level, continuing this process until reaching the bottom layer. The RNGs in the bottom layer generate random numbers, which then propagate upward through the layers until the top layer's X RNGs produce the final random numbers.
##### Thus, the computational complexity of RNGX is x*(y^z)
> [!Note]
> It requires a large amount of memory, especially for larger models. Models with (..., ..., 30) or fewer parameters can run on small PC or office computers (16GB RAM). Models with (..., ..., 300 or 3000) parameters can run on high-memory  or small to medium-sized servers. Models with (..., ..., 30000 or 300000) parameters are suitable for large servers or supercomputers.
