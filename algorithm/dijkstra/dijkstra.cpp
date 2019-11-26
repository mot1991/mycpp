// abolished
#include <iostream>
#include <array>
#include <map>
#include <algorithm>

#define LEN             (6)
#define UNLIMITED       (-1)

typedef struct _item
{
    bool is_find;
    int distance;
} Item;

// 测试图(有向图)
std::array<std::array<int, LEN>, LEN> g_arr_map = {{
    {0,         1,         12,        UNLIMITED, UNLIMITED, UNLIMITED},
    {UNLIMITED, 0,         9,         3,         UNLIMITED, UNLIMITED},
    {UNLIMITED, UNLIMITED, 0,         UNLIMITED, 5,         UNLIMITED},
    {UNLIMITED, UNLIMITED, 4,         0,         13,        15       },
    {UNLIMITED, UNLIMITED, UNLIMITED, UNLIMITED, 0,         4        },
    {UNLIMITED, UNLIMITED, UNLIMITED, UNLIMITED, UNLIMITED, 0        }
}};

int main(int argc, char* argv[])
{
    int _sreach = 0; // 设置起点
    std::map<int, Item> _res;

    // 初始化
    for(int idx = 0; idx < LEN; ++idx)
        _res[idx] = Item{false, UNLIMITED};

    // while(_sreach >= 0 && _sreach < LEN)
    // {
    //     for(int idx = 0; idx < LEN, ++idx)
    //     {
    //         if( (!_arr_is_find[idx])
    //             && (UNLIMITED != g_arr_map[_sreach][i]) )
    //         {
    //             _arr_res[i] = std::min(_arr_res[i], _arr_res[i] + g_arr_map[_sreach][i]);
    //         }
    //     }
    //     _arr_is_find[_sreach] = true;
    // }

    
    // std::copy(g_arr_map[start].begin(), g_arr_map[start].end(), _arr_res.begin());
    // std::for_each(_arr_res.begin(), _arr_res.end(), [](int i){ std::cout << i << std::endl;});



    return 0;
}