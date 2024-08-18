# RNGX
##### A random number generator that uses exponentiation-tree and pseudo-random enhancement levels to generate highly pseudo-random numbers.
##### (x,y,z)or version.version.version.version.x.y.z "x" represents the number of top-level RNGs, "y" represents the number of enhancement levels, and "z" represents the number of RNGs contained within each enhancement level.
### Principle
##### The top layer consists of the few RNGs that ultimately output the final random numbers, with the enhancement levels below them.
##### Each of the x RNGs at the top layer has y RNGs beneath them providing the seeds for generating random numbers. Similarly, each of these y RNGs also has y RNGs beneath them, which also provide seeds. In total, there are z groups of y RNGs. Dividing z*y by z gives the number of RNGs per enhancement level, and z represents the number of enhancement levels.
##### First, the x RNGs at the top layer send requests to the RNGs in the enhancement levels below them, asking them to generate random numbers as seeds. The RNGs below, in turn, send the same request to the RNGs in the next enhancement level down, continuing this process until it reaches the bottom layer. The bottom layer then generates random numbers that are passed up through the layers, eventually reaching the top x RNGs, which then combine to produce the final random number.
##### Thus, the computational complexity of RNGX is x*(y^z)
> [!Note]
> It requires a large amount of memory, especially for larger models. Models with (..., ..., 30) or fewer parameters can run on small PC or office computers (16GB RAM). Models with (..., ..., 300 or 3000) parameters can run on high-memory  or small to medium-sized servers. Models with (..., ..., 30000 or 300000) parameters are suitable for large servers or supercomputers.
