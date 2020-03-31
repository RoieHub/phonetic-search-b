
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


TEST_CASE("Test replacement of p and b") {
    string text = "be happy puppy";
    CHECK(find(text, "pe") == string("be"));
    CHECK(find(text, "pupby") == string("puppy"));
    CHECK(find(text, "buppy") == string("puppy"));
    CHECK(find(text, "pubpy") == string("puppy"));
    CHECK(find(text, "bupby") == string("puppy"));
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    
}

TEST_CASE("Test replacement of w and v") {
    string text = "vy wv waste vanagevent";
    CHECK(find(text, "vy") == string("vy"));
    CHECK(find(text, "vw") == string("wv"));
    CHECK(find(text, "vaste") == string("waste"));
    CHECK(find(text, "wanagevent") == string("vanagevent"));
    CHECK(find(text, "wanagewent") == string("vanagevent"));
    CHECK(find(text, "vanagewent") == string("vanagevent"));
    CHECK(find(text, "Wy") == string("vy"));
    CHECK(find(text, "vw") == string("wv"));
    CHECK(find(text, "Wv") == string("wv"));
    CHECK(find(text, "vaste") == string("waste"));
    CHECK(find(text, "Wanagevent") == string("vanagevent"));
    CHECK(find(text, "WanageWent") == string("vnagevent"));
    CHECK(find(text, "ManageWent") == string("vanagevent"));
    CHECK(find(text, "vY") == string("vy"));
    CHECK(find(text, "wv") == string("wv"));
    CHECK(find(text, "Waste") == string("waste"));
    CHECK(find(text, "vanagevent") == string("vanagevent"));
    CHECK(find(text, "vanagevent") == string("vanagevent"));
    CHECK(find(text, "vanagevent") == string("vanagevent"));
}

TEST_CASE("Test replacement of b,p and f") {
    string text = "pbug fun bpf proffesionel ";
    CHECK(find(text, "ffug") == string("pbug"));
    CHECK(find(text, "fbug") == string("pbug"));
    CHECK(find(text, "pfug") == string("pbug"));
    CHECK(find(text, "ppug") == string("pbug"));
    CHECK(find(text, "pbug") == string("pbug"));
    CHECK(find(text, "bfug") == string("pbug"));
    CHECK(find(text, "bun") == string("fun"));
    CHECK(find(text, "pun") == string("fun"));
    CHECK(find(text, "Bun") == string("fun"));
    CHECK(find(text, "Pun") == string("fun"));
    CHECK(find(text, "bbf") == string("bpf"));
    CHECK(find(text, "bpb") == string("bpf"));
    CHECK(find(text, "bbb") == string("bpf"));
    CHECK(find(text, "ppf") == string("bpf"));
    CHECK(find(text, "bpp") == string("bpf"));
    CHECK(find(text, "ppp") == string("bpf"));
    CHECK(find(text, "fff") == string("bpf"));
    CHECK(find(text, "fpf") == string("bpf"));
    CHECK(find(text, "bff") == string("bpf"));
    CHECK(find(text, "Proffesionel") == string("proffesionel"));
    CHECK(find(text, "proFfesionel") == string("proffesionel"));
    CHECK(find(text, "propfesionel") == string("proffesionel"));
    CHECK(find(text, "profFesionel") == string("proffesionel"));
    CHECK(find(text, "proffesionel") == string("proffesionel"));
    CHECK(find(text, "probfesionel") == string("proffesionel"));
    CHECK(find(text, "profbesionel") == string("proffesionel"));
    CHECK(find(text, "broffesionel") == string("proffesionel"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "grape juice";
    CHECK(find(text, "Grape") == string("grape"));
    CHECK(find(text, "jrape") == string("grape"));
    CHECK(find(text, "Jrape") == string("grape"));
    CHECK(find(text, "Juice") == string("juice"));
    CHECK(find(text, "guice") == string("juice"));
    CHECK(find(text, "Guice") == string("juice"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "swim zero suzen";
    CHECK(find(text, "Swim") == string("swim"));
    CHECK(find(text, "Zwim") == string("swim"));
    CHECK(find(text, "zwim") == string("swim"));
    CHECK(find(text, "Sero") == string("zero"));
    CHECK(find(text, "Zero") == string("zero"));
    CHECK(find(text, "sero") == string("zero"));
    CHECK(find(text, "zuzen") == string("suzen"));
    CHECK(find(text, "Zuzen") == string("suzen"));
    CHECK(find(text, "ZuZen") == string("suzen"));
    CHECK(find(text, "Suzen") == string("suzen"));
    CHECK(find(text, "SuZen") == string("suzen"));
    CHECK(find(text, "susen") == string("suzen"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "dont stop dreams";
    CHECK(find(text, "Dont") == string("dont"));
    CHECK(find(text, "tont") == string("dont"));
    CHECK(find(text, "Tont") == string("dont"));
    CHECK(find(text, "dond") == string("dont"));
    CHECK(find(text, "Dont") == string("dont"));
    CHECK(find(text, "sDop") == string("stop"));
    CHECK(find(text, "sdop") == string("stop"));
    CHECK(find(text, "sTop") == string("stop"));
    CHECK(find(text, "sreams") == string("dreams"));
    CHECK(find(text, "Sreams") == string("dreams"));
    CHECK(find(text, "dreamD") == string("dreams"));
    CHECK(find(text, "dreamS") == string("dreams"));
}

TEST_CASE("TTest replacement of o and u") {
    string text = "orange full union";
    CHECK(find(text, "Urange") == string("orange"));
    CHECK(find(text, "Orange") == string("orange"));
    CHECK(find(text, "urange") == string("orange"));
    CHECK(find(text, "fOll") == string("full"));
    CHECK(find(text, "foll") == string("full"));
    CHECK(find(text, "fUll") == string("full"));
    CHECK(find(text, "Onion") == string("union"));
    CHECK(find(text, "Union") == string("union"));
    CHECK(find(text, "uniUn") == string("union"));
    CHECK(find(text, "uniOn") == string("union"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "you like university";
    CHECK(find(text, "iou") == string("you"));
    CHECK(find(text, "Iou") == string("you"));
    CHECK(find(text, "You") == string("you"));
    CHECK(find(text, "lYke") == string("like"));
    CHECK(find(text, "lyke") == string("like"));
    CHECK(find(text, "lIke") == string("like"));
    CHECK(find(text, "unYversity") == string("university"));
    CHECK(find(text, "unyversity") == string("university"));
    CHECK(find(text, "universiti") == string("university"));
    CHECK(find(text, "universitI") == string("university"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "hAppi") == string("Happi"));
    CHECK(find(text, "haPpi") == string("Happi"));
    CHECK(find(text, "HapPi") == string("Happi"));
    CHECK(find(text, "HappI") == string("Happi"));
    CHECK(find(text, "HappI") == string("Happi"));
    CHECK(find(text, "HAppi") == string("Happi"));
    CHECK(find(text, "HapPI") == string("Happi"));

}

TEST_CASE("Test replacement of c,k and q") {
    string text = "quik choko quico ";
    CHECK(find(text, "cuik") == string("quik"));
    CHECK(find(text, "quic") == string("quik"));
    CHECK(find(text, "quiq") == string("quik"));
    CHECK(find(text, "cuiq") == string("quik"));
    CHECK(find(text, "qhoko") == string("choko"));
    CHECK(find(text, "choqo") == string("choko"));
    CHECK(find(text, "choco") == string("choko"));
    CHECK(find(text, "khoko") == string("choko"));
    CHECK(find(text, "cuico") == string("quico"));
    CHECK(find(text, "quiko") == string("quico"));
    CHECK(find(text, "kuico") == string("quico"));
    CHECK(find(text, "kuiqo") == string("quico"));
}

