#ifndef __rnd__
#define __rnd__

#include <cstdlib>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел в диапазоне от 1 до 20
//------------------------------------------------------------------------------

inline auto RandomNumber() {
    return rand() % 20 + 1;
}

inline auto RandomTreeName() {
    string treeNames[10]  = { "acacia", "birch" , "walnut" , "oak" , "willow" , "chestnut" , "olive" , "palm" , "pine" , "poplar" };
    string name = treeNames[rand() % 10];
    return name;
}

inline auto RandomShrubName() {
    string treeNames[10] = { "elder", "heather" , "jasmine" , "sea-buckthorn" , "nut-grove" , "	ivy" , "blackthorn" , "dog-rose" , "box-tree" , "honey-suckle" };
    string name = treeNames[rand() % 10];
    return name;
}

inline auto RandomFlowerName() {
    string treeNames[10] = { "pansies", "cornflower" , "carnation" , "dahlia" , "gladiolus" , "iris" , "bluebell" , "lavender" , "lily" , "poppy" };
    string name = treeNames[rand() % 10];
    return name;
}

#endif //__rnd__
