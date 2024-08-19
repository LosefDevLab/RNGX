// RNGX VERSION 1.0.R8.B6
// MODEL (4520,30000)

#include <iostream>
#include <vector>
#include <random>

// RNG类：表示一个随机数生成器
class RNG {
public:
    // 默认构造函数，使用随机设备种子初始化
    RNG() : rng(std::random_device{}()) {}
    // 带种子的构造函数
    RNG(int seed) : rng(seed) {}

    // 生成一个在min和max之间的随机整数
    int generate(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

private:
    std::mt19937 rng;
};

// RNGX类：表示一个多层级的随机数生成器
class RNGX {
public:
    // 创建一个新的增强级，包含num个RNG
    void createChild(int num) {
        levels.emplace_back(std::vector<RNG>(num));
    }

    // 生成一个随机数，通过多层级的RNG传递种子
    int GenRNG(int min, int max) {
        // 从最底层开始，逐层向上生成随机数
        for (int i = levels.size() - 1; i >= 0; --i) {
            // 在每一层中，从后向前生成随机数，并将结果作为下一个RNG的种子
            for (int j = levels[i].size() - 1; j >= 0; --j) {
                int seed = (j == levels[i].size() - 1) ?
                    levels[i][j].generate(min, max) : // 最右边的RNG生成新种子
                    levels[i][j + 1].generate(min, max); // 其他RNG使用前一个RNG的输出作为种子
                levels[i][j] = RNG(seed);
            }
        }
        // 返回最顶层第一个RNG生成的随机数
        return levels[0][0].generate(min, max);
    }

    // 加载预设的增强级结构
    int loading() {
        // 创建4520个增强级
        for (int i = 0; i < 565; i++) {
            for (int j = 0; j < 8; ++j) {
                createChild(y);
            }
        }
        return 0;
    }

    // 生成一个随机数，调用GenRNG函数
    int Gen(int min, int max) {
        int result = GenRNG(min, max);
        return result;
    }

private:
    std::vector<std::vector<RNG>> levels;
    // 每个增强级包含的RNG数量
    int y = 30000;
};