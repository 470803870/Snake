#include "Apple.hpp"

// 根据地图的大小和蛇的坐标随机生成苹果
Apple::Apple(const std::deque<Vector> &m_snake, const Vector &map)
{
    short random, x, y;
    bool isExists;
    while (true)
    {
        isExists = false;
        // 根据地图大小随机生成坐标
        random = rand() % (map.x * map.y);
        x = random % map.x;
        y = random / map.y;
        // 如果坐标是蛇的坐标，重新生成随机坐标
        for (auto it : m_snake)
        {
            if (it == Vector({x, y}))
                isExists = true;
        }
        // 新坐标不是蛇的坐标，跳出循环
        if (!isExists)
            break;
    }
    m_apple = Vector(x, y);
}

// 返回坐标
const Vector &Apple::getVector() const
{
    return m_apple;
} 