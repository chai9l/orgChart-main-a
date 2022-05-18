#include "doctest.h"
#include "sources/OrgChart.hpp"

using namespace ariel;

TEST_CASE("Kingdom") {
    OrgChart kingdom;
    kingdom.add_root("King");
    // Royal Family
    kingdom.add_sub("Queen", "King");
    kingdom.add_sub("Prince", "Queen");
    kingdom.add_sub("Princess", "Queen");
    // Knights
    kingdom.add_sub("Knight Captain", "King");
    kingdom.add_sub("Squad Captain 1", "Knight Captain");
    kingdom.add_sub("Squad Captain 2", "Knight Captain");
    kingdom.add_sub("Knight 1", "Squad Captain 1");
    kingdom.add_sub("Knight 2", "Squad Captain 1");
    kingdom.add_sub("Knight 1", "Squad Captain 2");
    kingdom.add_sub("Knight 2", "Squad Captain 2");
    // Right Hand etc
    kingdom.add_sub("Right Hand", "King");
    kingdom.add_sub("Consultant", "Right Hand");
    kingdom.add_sub("Head Chef", "Right Hand");
    kingdom.add_sub("Head Maid", "Right Hand");
    // Kitchen
    kingdom.add_sub("Cook 1", "Head Chef");
    kingdom.add_sub("Cook 2", "Head Chef");
    // Maids
    kingdom.add_sub("Maid 1", "Head Maid");
    kingdom.add_sub("Maid 2", "Head Maid");
    // City
    kingdom.add_sub("Mayor", "King");
    for(size_t i = 1; i < 1000; i++) {
        string temp_peasant = "Peasant "+to_string(i);
        kingdom.add_sub(temp_peasant, "Mayor");
    }
    CHECK_NOTHROW(kingdom.add_sub("Peasant 10", "Mayor"));

    /////////////////////////////////////// Kingdom Chart ////////////////////////////////////////////////////////////////////////////////////
    //                                         (King)                                                                                       //
    //                                           |                                                                                          //
    //                  ----------------------------------------------------------------------------------------------------                //
    //                  |                        |                               |                                         |                //
    //               (Queen)              (Knight Captain)                 (Right Hand)                                 (Mayor)             //
    //                  |                        |                               |                                         |                //
    //              ---------            ------------------                -------------------------------            ------------          // 
    //              |       |            |                |                |              |              |            |    ...   |          //
    //         (Prince) (Princess) (Squad Captain 1) (Squad Captain 2) (Consultant)  (Head Chef)    (Head Maid)  (Peasant1)...(Peasant10)   //
    //                                   |                |                               |              |                                  //
    //                              ------------        ------------                   --------        -------                              //
    //                              |          |        |          |                   |      |        |      |                             //
    //                         (Knight 1) (Knight 2) (Knight 3)  (Knight 4)         (Cook1) (Cook2) (Maid1) (Maid2)                         //
    //                                                                                                                                      //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<string> pre_order = {"King", "Queen", "Prince", "Princess",
                                "Knight Captain", "Squad Captain 1", "Knight 1", "Knight 2", 
                                "Squad Captain 2", "Knight 3", "Knight 4"
                                "Right Hand", "Consultant", "Head Chef", "Cook 1", "Cook 2", "Head Maid", "Maid 1", "Maid 2",
                                "Mayor", "Peasant 1", "Peasant 2", "Peasant 3", "Peasant 4", "Peasant 5", "Peasant 6", "Peasant 7", "Peasant 8", "Peasant 9", "Peasant 10"
                                };
    
    vector<string> lev_order = {"King","Queen", "Knight Captain", "Right Hand", "Mayor"
                "Prince", "Princess", "Squad Captain 1", "Squad Captain 2", "Consultant", "Head Chef",
                "Peasant 1", "Peasant 2", "Peasant 3", "Peasant 4", "Peasant 5", "Peasant 6", "Peasant 7", "Peasant 8", "Peasant 9", "Peasant 10"
                "Knight 1", "Knight 2", "Knight 3", "Knight 4", "Cook 1", "Cook 2", "Maid 1", "Maid 2"};
    
    vector<string> rev_order;
    u_int counter = 0;
    for (size_t i = lev_order.size()-1; i == 0; i--) {
        rev_order[counter] = lev_order[i];
        counter++;
    }

    OrgChart::iter pre_order_iter = kingdom.begin_preorder();
    OrgChart::iter lev_order_iter = kingdom.begin_level_order();
    OrgChart::iter rev_order_iter = kingdom.begin_reverse_order();

    for (size_t i = 0; i < pre_order.size(); i++) {
        ++pre_order_iter;
        CHECK_EQ(pre_order[i], *pre_order_iter);
    }

    for (size_t i = 0; i < lev_order.size(); i++) {
        ++lev_order_iter;
        CHECK_EQ(lev_order[i], *lev_order_iter);
    }

    for (size_t i = 0; i < rev_order.size(); i++) {
        ++rev_order_iter;
        CHECK_EQ(rev_order[i], *rev_order_iter);
    }

    CHECK_THROWS(kingdom.add_sub("Squire", "DO NOT EXSIST"));
    
}
