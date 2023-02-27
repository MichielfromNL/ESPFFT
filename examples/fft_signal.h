
#define FFT_N 2048 // Must be a power of 2
#define TOTAL_TIME 9.391904 //The time in which data was captured. This is equal to FFT_N/sampling_freq



/* 
 * test data. Output of an I2S sampler
 * Amplitude: 0.25g
*/
const float samples[FFT_N] = {
{-128,-214,-176,-80,-100,-108,-65,-98,-89,-30,-9,10,80,45,76,168,206,338,349,363,487,545,497,503,552,483,391,419,389,350,268,140,163,121,106,128,51,64,128,131,84,105,133,23,-15,64,42,-21,-101,-148,-118,-185,-150,-198,-260,-231,-204,-251,-270,-240,-318,-390,-272,-258,-359,-373,-346,-340,-326,-234,-236,-233,-209,-124,-67,-102,-47,0,-64,18,131,72,31,61,61,62,99,121,95,106,97,164,164,60,121,131,32,178,223,120,157,168,154,189,225,229,242,227,263,316,228,215,270,157,131,248,179,56,53,18,-36,-73,-69,-134,-217,-227,-177,-262,-314,-250,-322,-340,-209,-228,-277,-218,-215,-229,-168,-112,-105,-143,-161,-90,-66,-129,-145,-127,-157,-118,-43,-104,-124,-72,-53,2,49,147,163,146,221,283,295,310,317,294,302,376,357,290,286,232,243,210,210,224,129,84,104,91,8,-24,-16,-66,-22,-11,-57,-46,-76,-59,-49,-30,9,-79,-145,-91,-102,-180,-215,-225,-274,-254,-169,-196,-216,-198,-156,-106,-167,-75,-24,-98,-101,-46,-51,-97,-115,-174,-214,-137,-123,-171,-147,-224,-146,-83,-81,39,63,92,162,187,204,214,203,135,157,212,138,111,101,18,92,61,97,173,123,166,221,225,267,271,213,268,350,310,293,299,202,255,232,198,218,100,55,55,-52,-168,-183,-229,-349,-312,-294,-363,-321,-390,-399,-297,-311,-226,-203,-222,-162,-166,-212,-198,-200,-294,-309,-231,-256,-277,-259,-359,-263,-191,-156,-84,-56,19,61,68,121,162,141,122,164,199,178,174,127,151,173,167,231,219,268,307,294,307,338,316,283,296,327,297,243,199,100,153,127,106,119,51,72,54,-14,-6,-7,-66,-64,-44,-15,-37,-68,-117,-130,-79,-111,-110,-148,-166,-153,-269,-319,-301,-372,-398,-425,-429,-400,-388,-381,-427,-350,-294,-215,-168,-183,-76,-43,-67,-47,-17,-36,-13,-21,11,36,16,-31,55,87,131,200,200,275,315,326,342,393,402,404,408,460,459,393,362,335,380,344,340,309,248,264,230,154,78,61,36,-51,-106,-75,-134,-212,-303,-296,-279,-323,-286,-352,-372,-357,-358,-418,-453,-430,-461,-493,-437,-424,-456,-448,-446,-349,-324,-265,-199,-126,-82,-34,-54,-47,8,-3,-15,70,88,58,103,122,193,234,284,350,377,389,440,473,402,409,435,396,379,416,358,319,292,257,281,224,249,238,169,141,138,94,-11,-41,-48,-105,-109,-109,-201,-185,-260,-247,-205,-224,-172,-183,-176,-138,-110,-178,-213,-183,-225,-272,-228,-315,-376,-390,-416,-356,-352,-321,-297,-239,-190,-129,-125,-143,-97,-84,-61,-6,-76,-70,-19,-89,-39,0,70,80,62,138,191,216,223,231,253,274,337,336,258,322,316,281,339,331,353,337,341,353,344,306,274,261,205,182,240,139,76,125,47,17,47,81,35,-43,-15,-4,-27,-106,-186,-216,-287,-253,-381,-521,-492,-552,-597,-599,-565,-543,-576,-498,-420,-401,-391,-316,-294,-292,-206,-146,-196,-196,-159,-170,-126,-120,-66,-62,-40,40,106,140,163,229,264,317,415,448,425,476,490,509,504,521,544,488,458,498,471,366,330,333,234,199,259,179,69,57,30,61,-13,-50,-89,-150,-104,-127,-231,-281,-276,-347,-382,-319,-415,-478,-443,-467,-425,-423,-413,-374,-403,-362,-284,-287,-354,-286,-307,-370,-257,-193,-291,-293,-273,-220,-147,-189,-108,-54,-43,90,175,173,247,334,334,389,516,553,486,536,534,597,557,503,560,502,410,479,455,348,331,325,242,267,351,159,177,162,206,193,71,126,59,-26,17,-19,-155,-237,-206,-336,-436,-320,-450,-574,-533,-583,-534,-586,-577,-536,-586,-557,-456,-457,-554,-498,-447,-520,-409,-342,-446,-407,-372,-314,-241,-249,-169,-152,-95,-24,72,65,71,181,171,219,376,390,335,394,427,472,495,469,498,519,508,548,527,426,462,432,393,456,444,284,280,274,244,239,192,148,99,93,103,51,4,-48,-66,-95,-61,-56,-129,-183,-172,-164,-194,-193,-209,-225,-184,-199,-191,-263,-273,-244,-322,-327,-289,-290,-370,-414,-397,-449,-437,-395,-405,-438,-377,-343,-321,-260,-239,-193,-133,-75,14,32,41,93,119,122,196,205,159,242,233,201,249,270,294,256,324,358,397,370,351,400,373,374,407,360,315,317,312,274,203,165,119,115,49,-31,-45,-205,-234,-250,-373,-388,-362,-390,-425,-403,-431,-407,-385,-391,-323,-283,-289,-184,-217,-285,-175,-161,-172,-123,-101,-136,-55,-26,-34,11,54,86,170,204,291,283,226,336,348,313,350,375,346,338,360,308,256,246,222,251,235,170,219,76,54,116,38,-27,5,-35,-78,-42,-69,-142,-134,-143,-116,-69,-147,-84,-97,-251,-154,-100,-172,-201,-120,-153,-99,-87,-139,-114,-90,-61,-31,-52,-37,-29,-84,-162,-119,-119,-193,-228,-195,-258,-217,-216,-231,-216,-150,-102,-41,-28,30,-5,-34,52,48,-13,-8,11,3,-11,-10,-56,-66,-25,-6,45,76,137,158,102,176,278,256,212,275,267,298,312,288,216,236,252,271,268,282,277,190,151,173,172,110,76,56,45,90,66,51,33,32,73,102,118,121,83,32,-4,22,-58,-130,-155,-182,-146,-204,-257,-287,-243,-225,-218,-127,-120,-136};
};
