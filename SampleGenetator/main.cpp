//std
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdint>
#include <functional>
#include <thread>
#include <mutex>
#include <memory>
#include <iomanip>
#include <sstream>
//3rd
#include <leveldb/db.h>
#include <leveldb/write_batch.h>
//own
#include "caffe.pb.h"
#include "SampleGenetator.h"
#include "scopeExit.h"

static const uchar bgColor = 155;
static const uchar fgColor = 0;

static std::wstring getChineseTable()
{
	static const std::wstring chineseTable = L"µÄÒ»ÊÇ²»ÁËÔÚÈËÓĞÎÒËûÕâ¸öÃÇÖĞÀ´ÉÏ´óÎªºÍ¹úµØµ½ÒÔËµÊ±Òª¾Í³ö»á¿ÉÒ²Äã¶ÔÉúÄÜ¶ø×ÓÄÇµÃÓÚ×ÅÏÂ×ÔÖ®Äê¹ı·¢ºó×÷ÀïÓÃµÀĞĞËùÈ»¼ÒÖÖÊÂ³É·½¶à¾­Ã´È¥·¨Ñ§Èç¶¼Í¬ÏÖµ±Ã»¶¯ÃæÆğ¿´¶¨Ìì·Ö»¹½øºÃĞ¡²¿ÆäĞ©Ö÷ÑùÀíĞÄËı±¾Ç°¿ªµ«ÒòÖ»´ÓÏëÊµÈÕ¾üÕßÒâÎŞÁ¦ËüÓë³¤°Ñ»úÊ®ÃñµÚ¹«´ËÒÑ¹¤Ê¹ÇéÃ÷ĞÔÖªÈ«ÈıÓÖ¹ØµãÕıÒµÍâ½«Á½¸ß¼äÓÉÎÊºÜ×îÖØ²¢ÎïÊÖÓ¦Õ½ÏòÍ·ÎÄÌåÕşÃÀÏà¼û±»ÀûÊ²¶şµÈ²ú»òĞÂ¼ºÖÆÉí¹û¼ÓÎ÷Ë¹ÔÂ»°ºÏ»ØÌØ´úÄÚĞÅ±í»¯ÀÏ¸øÊÀÎ»´Î¶ÈÃÅÈÎ³£ÏÈº£Í¨½Ì¶ùÔ­¶«ÉùÌáÁ¢¼°±ÈÔ±½âË®ÃûÕæÂÛ´¦×ßÒå¸÷Èë¼¸¿ÚÈÏÌõÆ½ÏµÆøÌâ»î¶û¸ü±ğ´òÅ®±äËÄÉñ×ÜºÎµçÊı°²ÉÙ±¨²Å½á·´ÊÜÄ¿Ì«Á¿ÔÙ¸Ğ½¨Îñ×ö½Ó±Ø³¡¼ş¼Æ¹ÜÆÚÊĞÖ±µÂ×ÊÃüÉ½½ğÖ¸¿ËĞíÍ³Çø±£ÖÁ¶ÓĞÎÉç±ã¿Õ¾öÖÎÕ¹Âí¿ÆË¾Îå»ùÑÛÊé·ÇÔòÌı°×È´½ç´ï¹â·ÅÇ¿¼´ÏñÇÒÄÑÈ¨Ë¼ÍõÏóÍêÉèÊ½É«Â·¼ÇÄÏÆ·×¡¸æÀàÇó¾İ³Ì±±±ßËÀÕÅ¸Ã½»¹æÍòÈ¡À­¸ñÍû¾õÊõÁì¹²È·´«Ê¦¹ÛÇå½ñÇĞÔºÈÃÊ¶ºò´øµ¼ÕùÔËĞ¦·É·ç²½¸ÄÊÕ¸ù¸ÉÔìÑÔÁª³Ö×éÃ¿¼Ã³µÇ×¼«ÁÖ·ş¿ì°ìÒéÍùÔªÓ¢Ê¿Ö¤½üÊ§×ª·òÁî×¼²¼Ê¼ÔõÄØ´æÎ´Ô¶½ĞÌ¨µ¥Ó°¾ßÂŞ×Ö°®»÷Á÷±¸±øÁ¬µ÷ÉîÉÌËãÖÊÍÅ¼¯°ÙĞè¼Û»¨µ³»ª³ÇÊ¯¼¶Õû¸®Àë¿öÑÇÇë¼¼¼ÊÔ¼Ê¾¸´²¡Ï¢¾¿ÏßËÆ¹Ù»ğ¶Ï¾«ÂúÖ§ÊÓÏûÔ½Æ÷ÈİÕÕĞë¾ÅÔöÑĞĞ´³ÆÆó°Ë¹¦Âğ°üÆ¬Ê·Î¯ºõ²éÇáÒ×ÔçÔø³ıÅ©ÕÒ×°¹ãÏÔ°É°¢Àî±êÌ¸³ÔÍ¼ÄîÁùÒıÀúÊ×Ò½¾ÖÍ»×¨·ÑºÅ¾¡ÁíÖÜ½Ï×¢Óï½ö¿¼ÂäÇàËæÑ¡ÁĞÎäºìÏìËäÍÆÊÆ²ÎÏ£¹ÅÖÚ¹¹·¿°ë½ÚÍÁÍ¶Ä³°¸ºÚÎ¬¸ï»®µĞÖÂ³ÂÂÉ×ãÌ¬»¤ÆßĞËÅÉº¢ÑéÔğÓªĞÇ¹»ÕÂÒô¸úÖ¾µ×Õ¾ÑÏ°ÍÀı·À×å¹©Ğ§ĞøÊ©Áô½²ĞÍÁÏÖÕ´ğ½ô»Æ¾øÆæ²ìÄ¸¾©¶ÎÒÀÅúÈºÏî¹Ê°´ºÓÃ×Î§½­Ö¯º¦¶·Ë«¾³¿Í¼Í²É¾ÙÉ±¹¥¸¸ËÕÃÜµÍ³¯ÓÑËßÖ¹Ï¸Ô¸Ç§ÖµÈÔÄĞÇ®ÆÆÍøÈÈÖúµ¹ÓıÊô×øµÛÏŞ´¬Á³Ö°ËÙ¿ÌÀÖ·ñ¸ÕÍşÃ«×´ÂÊÉõ¶ÀÇò°ãÆÕÅÂµ¯Ğ£¿à´´¼Ù¾Ã´í³ĞÓ¡ÍíÀ¼ÊÔ¹ÉÄÃÄÔÔ¤Ë­ÒæÑôÈôÄÄÎ¢Äá¼ÌËÍ¼±Ñª¾ªÉËËØÒ©ÊÊ²¨Ò¹Ê¡³õÏ²ÎÀÔ´Ê³ÏÕ´ıÊöÂ½Ï°ÖÃ¾ÓÀÍ²Æ»·ÅÅ¸£ÄÉ»¶À×¾¯»ñÄ£³ä¸ºÔÆÍ£Ä¾ÓÎÁúÊ÷ÒÉ²ãÀäÖŞ³åÉäÂÔ·¶¾¹¾äÊÒÒì¼¤ºº´å¹ş²ßÑİ¼ò¿¨×ïÅĞµ£Öİ¾²ÍË¼ÈÒÂÄú×Ú»ıÓàÍ´¼ì²î¸»ÁéĞ­½ÇÕ¼ÅäÕ÷ĞŞÆ¤»ÓÊ¤½µ½×Éó³Á¼áÉÆÂèÁõ¶Á°¡³¬ÃâÑ¹ÒøÂò»ÊÑøÒÁ»³Ö´¸±ÂÒ¿¹·¸×·°ïĞû·ğËêº½ÓÅ¹ÖÏãÖøÌïÌú¿ØË°×óÓÒ·İ´©ÒÕ±³Õó²İ½Å¸Å¶ñ¿é¶Ù¸ÒÊØ¾ÆµºÑëÍĞ»§ÁÒÑó¸çË÷ºú¿î¿¿ÆÀ°æ±¦×ùÊÍ¾°¹ËµÜµÇ»õ»¥¸¶²®ÂıÅ·»»ÎÅÎ£Ã¦ºË°µ½ã½é»µÌÖÀöÁ¼ĞòÉı¼àÁÙÁÁÂ¶ÓÀºôÎ¶Ò°¼ÜÓòÉ³µôÀ¨½¢ÓãÔÓÎóÍå¼ª¼õ±à³ş¿Ï²â°ÜÎİÅÜÃÎÉ¢ÎÂÀ§½£½¥·â¾È¹óÇ¹È±Â¥ÏØÉĞºÁÒÆÄïÅó»­°àÖÇÒà¶ú¶÷¶ÌÕÆ¿ÖÒÅ¹ÌÏ¯ËÉÃØĞ»Â³Óö¿µÂÇĞÒ¾ùÏúÖÓÊ«²Ø¸Ï¾çÆ±Ëğºö¾ŞÅÚ¾É¶ËÌ½ºşÂ¼Ò¶´ºÏç¸½ÎüÓèÀñ¸ÛÓêÑ½°åÍ¥¸¾¹é¾¦·¹¶îº¬Ë³ÊäÒ¡ÕĞ»éÍÑ²¹Î½¶½¶¾ÓÍÁÆÂÃÔó²ÄÃğÖğÄª±ÊÍöÏÊ´ÊÊ¥ÔñÑ°³§Ë¯²©ÀÕÑÌÊÚÅµÂ×°¶°ÂÌÆÂô¶íÕ¨ÔØÂå½¡ÌÃÅÔ¹¬ºÈ½è¾ı½ûÒõÔ°Ä±ËÎ±Ü×¥ÈÙ¹ÃËïÌÓÑÀÊøÌø¶¥ÓñÕòÑ©ÎçÁ·Ò¯ÆÈÆªÈâ×ì¹İ±é·²´¡¶´¾íÌ¹Å£ÄşÖ½ÖîÑµË½×¯×æË¿·­±©É­ËşÄ¬ÎÕÏ·ÒşÊì¹Ç·ÃÈõÃÉ¸èµê¹íÈíµäÓûÈø»ïÔâÅÌ°ÖÀ©¸ÇÅªĞÛÎÈÍüÒÚ´ÌÓµÍ½Ä·ÑîÆëÈüÈ¤Çúµ¶´²Ó­±ùĞéÍæÎö´°ĞÑÆŞÍ¸¹ºÌæÈûÅ¬Ğİ»¢ÑïÍ¾ÇÖĞÌÂÌĞÖÑ¸Ì×Ã³±ÏÎ¨¹ÈÂÖ¿â¼£ÓÈ¾º½Ö´ÙÑÓÕğÆú¼×Î°Âé´¨Éê»ºÇ±ÉÁÊÛµÆÕëÕÜÂçµÖÖì°£±§¹ÄÖ²´¿ÏÄÈÌÒ³½ÜÖşÕÛÖ£±´×ğÎâĞã»ì³¼ÑÅÕñÈ¾Ê¢Å­ÎèÔ²¸ã¿ñ´ëĞÕ²ĞÇïÅàÃÔ³Ï¿íÓîÃÍ°ÚÃ·»ÙÉìÄ¦ÃËÄ©ÄË±¯ÅÄ¶¡ÕÔÓ²Âó½¯²Ù×è¶©²Ê³éÔŞÄ§·×ÑØº°Î¥ÃÃÀË»ã±Ò·áÀ¶ÊâÏ××ÀÀ²ÍßÀ³Ô®Òë¶áÆûÉÕ¾à²ÃÆ«·ûÓÂ´¥¿Î¾´¿Ş¶®Ç½ÕÙÏ®·£ÏÀÌü°İÇÉ²àº«Ã°Õ®ÂüÈÚ¹ßÏí´÷Í¯ÓÌ³Ë¹Ò½±ÉÜºñ×İÕÏÑ¶Éæ³¹¿¯ÕÉ±¬ÎÚÒÛÃèÏ´Âê»¼Ãî¾µ³ª·³Ç©ÏÉ±ËÖ¢·ÂÇãÅÆÏİÄñºäÔÛ²Ë±Õ·ÜÇì³·Àá²è¼²Ôµ²¥ÀÊ¶ÅÄÌ¼¾µ¤¹·Î²ÒÇÍµ±¼Öé³æ×¤¿×ÒË°¬ÇÅµ­ÒíºŞ·±º®°éÌ¾µ©Óú³±Á¸Ëõ°Õ¾Û¾¶Ç¡Ìô´ü»Ò²¶ĞìÕäÄ»Ó³ÁÑÌ©¸ôÆô¼âÖÒÀÛÑ×Ôİ¹À·º»Ä³¥ºá¾ÜÈğÒä¹Â±ÇÄÖÑò´ôÀ÷ºâ°ûÁãÇîÉáÂëºÕÆÅ»êÔÖºéÍÈµ¨½òË×±çĞØÏş¾¢ÈÊÆ¶Å¼¼­°î»ÖÀµÈ¦ÃşÑöÈó¶ÑÅöÍ§ÉÔ³ÙÁ¾·Ï¾»Ğ×Êğ±ÚÓù·îĞı¶¬¿óÌ§µ°³¿·ü´µ¼¦±¶ºıÇØ¶Ü±­×âÆï·¦Â¡ÕïÅ«ÉãÉ¥ÎÛ¶ÉÆì¸ÊÄÍÆ¾ÔúÇÀĞ÷´Ö¼çÁº»Ã·Æ½ÔËéÖæÊåÑÒµ´×ÛÅÀºÉÏ¤µÙ·µ¾®×³±¡ÇÄÉ¨Ãô°­Ö³ÏêÃ¬»ôÔÊ·ùÈöÊ£¿­¿ÅÂîÉÍÒº·¬ÏäÌùÂşËáÀÉÑüÊæÃ¼ÓÇ¸¡ĞÁÁµ²ÍÏÅÍ¦Àø´ÇËÒ¼üÎé·å³ß×òÀè±²¹áÕì»¬È¯³çÈÅÏÜÈÆÇ÷´ÈÇÇÔÄº¹Ö¦ÍÏÄ«Ğ²²å¼ıÀ°Äà·ÛÊÏÅí°ÎÆ­·ï»ÛÃ½Åå·ßÆËÁäÇıÏ§ÑÚºÀ¼æÔ¾Ê¬ËàÅÁÊ»±¤½ìĞÀ»İ²á´¢Æ®É£ÏĞ²Ò½à×Ù²ª±öÆµ³ğÄ¥µİĞ°×²Äâ¹ö×àÑ²ÑÕ¼Á¼¨¹±·èÆÂÇÆ½ØÈ¼½¹µîÎ±ÁøËø±ÆÆÄ»èÈ°³ÊËÑÇÚ½ä¼İÆ¯Òû²Ü¶ä×ĞÈáÁ©ÃÏ¸¯Ó×¼ù¼®ÄÁÁ¹Éü¼ÑÄÈÅ¨·¼¸åÖñ¸¹µøÂß´¹×ñÂöÃ²°ØÓü²ÂÁ¯»óÌÕÊŞÕÊÊÎ´û²ıĞğÌÉ¸Ö¹µ¼Ä·öÆÌµËÊÙ¾åÑ¯ÌÀµÁ·Ê³¢´Ò»ÔÄÎ¿ÛÍ¢°Ä¶­Ç¨ÄıÎ¿ÑáÔàÌÚÓÄÔ¹Ğ¬¶ªÂñÈªÓ¿Ï½¶ã½ú×Ï¼èÎº»Å×£ÓÊÍÂºİ¼øĞµÒ§ÁÚ³à¼·ÍäÒÎÅã¸î½ÒÎò´ÏÎí·æÌİÏéÃ¨À«Óş³ï´ÔÇ£ÃùÉò¸óÄÂÇüÖ¼ĞäÁÔ±ÛÉßºØÖùÅ×ÊóÉª¸êÀÎÑ·ÂõÆÛ¶ÖÇÙË¥Æ¿ÄÕÑàÖÙÓÕÀÇ³ØÌÛÂ¬ÕÌ¹ÚÁ£Ò£ÂÀĞş³¾·ë¸§Ç³¶Ø¾À×ê¾§ÆñÏ¿²ÔÅçºÄÁèÇÃ¾úÅâÍ¿´â±â¿÷¼ÅÃºĞÜ¹§ÊªÑ­Å¯ÌÇ¸³ÒÖÖÈÃ±°§ËŞÌ¤ÀÃÔ¬ºî¶¶¼ĞÀ¥¸Î²ÁÖíÁ¶ºãÉ÷°áÅ¦ÎÆ²£Óæ´ÅÍ­³İ¿çÑº²ÀÄ®Æ£ÅÑÇ²¼À×íÈ­ÃÖĞ±µµÏ¡½İ·ôÖ×Òß¶¹Ï÷¸Ú»ÎÍÌºê°©¶ÇÁ¥ÂÄÕÇÒ«Å¤Ì³ÎÖ²¦»æ·¥¿°ÆÍ¹ùÎş¼ßÄ¹¹ÍÁ®ÆõÆ´³Í×½¸²Ë¢½ÙÏÓ¹ÏĞªµñÃÆÈé´®ÍŞ½É»½Ó®Á«ÌÒ°ÔÍ×Êİ´î¸°ÔÀ¼Î²Õ¿¡Ö·ÅÓ¸ûÈñ·ì»ÚÑûÁá³âÕ¬ÌíÍÚºÇËÏÑõºÆÓğ½ï¿áÂÓÑı»öÊÌÒÒ·ÁÌ°ÕõÍôÄòÀòĞü´½º²²Ö¹ìÃ¶ÑÎÀÀ¸µË§Ãí·ÒÆÁËÂÅÖÁ§ÓŞµÎÊèÏô×Ë²ü³óÁÓ´çÈÓ¶¢ÈèÆ¥¾ã±æ¶ö·äÇ»ÓôÀ£½÷Ôã¸ğÃç³¦¼ÉÁïºè¾ôÅôÓ¥ÁıÇğ¹ğ×ÌÁÄµ²¸Ù¼¡¿ÇºÛÍëÑ¨°ò×¿ÏÍÎÔÄ¤ÒãÇ·½õÁ¨º¯Ã£°ºÑ¦Öå¿äÔ¥Î¸Éà°ş°ÁÊ°ÎÑÕöĞ¯ÁêºßÃŞÇçÁåÌîËÇ¿ÊÎÇ°çÄæ´à´­ÕÖ²·Â¯²ñÓäÉşÌ¥ĞîÃß½ßÎ¹ÉµÄ½»ë¼éÉÈ¹ñÔÃÀ¹µ®±¥Ç¬ÅİÔôÍ¤Ï¦µù³êÈåÒöÂÑ·ÕĞ¹¸Ë°¤É®ÃÛÒ÷ĞÉËìÏÁĞ¤ÌğÏ¼²µÔ£ÍçÕª°«ÃëÇäĞóÑÊÅû¸¨¹´Åè½®¶ÄËÜÎ·³³ÄÒ²´·ÎÖè²ø¸ÔĞßµÉµõÂ©¼Ö°ßÌÎÓÆÂ¹·ıÎı±°ÔáÃúÌ²¼Ş´ß³áºĞÂùÅËÆç´Í¹øÀÈ²ğ¹àÃãÃ¤Ô×É¶ÕÍ³¶ÁÉÄ¨Í²Æå¿ã°¦ÆÓ¸ÀÔĞÊÄºíÍı¾ĞÁ´³ÛÀ¸ÊÅÇÔÑŞÏË³ô¿Ã³Ã½³Ó¯ÎÌ³îË²Ó¤Ğ¢¾±ÌÈÕãÁÂ±Î³©ÔùÎ¾¶³¹ò´³ÆÏÑ¼³øµßÕÚÒêÓõÂØ±ÙÁöÉ©¿òÌ·ÇÕÓ¹Ç¸Ö¥ºğ¸¦ÉÀÑçÌ¯ÖöÖÔ½¿ÉÂ¾ØÆÖÑÈËÊÂã±Ì´İĞ½ÁÜ³Ü½ºÍÀ¶ì¼¢ÅÎ²±ºç´ä±ÀÕËÆ¼·ê×¬³ÅÏè³«Ãà¿İºïÎ×ÕÑÕúÔ¨´ÕÏª´À²ûÍúÔ¢ÌÙÉ¡·Ë±®Å²ÇíÖ¬»Ñ¿®ÆĞÌÑÊ¨¾ò³­ÁëÔÎ¿³´şÌÍÎúº±ÍìÆ¢ÖÛ³Õ¼ô¼¹¹­ÀÁ²æ¹ÕÁÅ¾èæ¢É§ÍØÍáÕ³±ú¿ÓÄ°Õ­ÏæÕ×ÑÂ½¾É²±ŞÃ¢½îÆ¸¹³¹÷ÈÂÏÙÏÒÑæË£¸©ÀåÏÃ¿ÒÈÄ¶¤¹Ñº¶Ë¤µşÈÇÓ÷Æ×À¢»Í»ÕÈÜ×¹É·½íÀÄÈ÷¶Â´ÉÖäÒÌ°ôÔ¡ÃÄ»´°¥ÆáÆ¨Òù³²·Ô×«Ğ¥ÖÍÃµË¶µöµûÏ¥Ò¦Ã¯ÇûÀôÔ³Õ¯Ë¡ÇşÆİ³½²°°ä»Ìºü·í±¿ÅÛ³°ÆÃ·ÈÏÎ¾ëº­È¸Ñ®Ëº½©Ö«Â¢ÒÄÒİÃ©ÇÈÓßÒ¤ÆÑÇ«º¼±×Ñ«¹Î½¼ÆàÅõ½ş×©¶¦ÀºÕôÄ¶±ıÉö¶¸×¦ÍÃÒóÕê¼öÑÆÌ¿·ØÕ£²«Â£¿È¾ËÃÁÉÃË¬¿§¸é´ÆÉÚ¹®¾îÂİ¹üÎôĞùÃıµı¹êÏ±½ªÏ¹Ô©Ñ»ÅîÏïÁÕÔÔÕ´Õ©Õ«Â÷±ë×É·Ä¹ŞÍ°ÈÀËÌ¸âÅòĞ³Àİ¹¾Ï¶À±°ó³èºÙ¶ÒÃ¹´ì»ü·øÆòÉ´È¹ĞåÕÈÌÁÑÜÖáÅÊ²²Æ©ÆíÌßËÁ¿²½ÎÅïÆüÂÅÔê»ËÒç×µÔÒÌËÁ±·«ÆÜ´ÜÍèÕ¶µÌËú··ÏáÏÆ¹ÔÃÕÄóÑÖÂ²±õ³×Â«Æ»Ğ¶ÕÓÔ¿Öêµ»ÆÊÎõ»©ÅüÇÓÌÄ¸ì×®¹åÓéÈ¢Ä­É¤¶×ÌÔ·ÙÄÛÔÏ³ÄĞÙÊú¾û¾ş±ªÀÌ¾Õ±ÉÆÇ¶µºåÓ±Ğ¼ÒÏºøÉøÍººµÓ´ÏÌÍğÇ´µ¾Öı¶Í±Ğ»Ğ±áÖòº§Ğ¾Ö­·»Â¿Ğà¾¸Ó¶ÂµÆù¼½¾£´ŞÑãÉğÉº°ñËĞ°ø´¼µÑÇİÎğÃé´±¿Ü»ß¶Ã²ÈÎØ¹°Ãï¸¿¹îÑÍÅñÍóÖó×ä¿±¶º¼úµé³´²Ó³¨À¯ÇôÀõ¹¼µæ¶Ê¿ıÒ¥Ä¯Ë¦ÊñÕíÑÄØ¤Ó¾ÃÚÓâ¶£ÔïÖÀÊàÔ÷¾¨ÒĞÎê·÷º×Ê´½¬Ü½À¬¿¾É¹Ëª½ËÔÌ»øÓì³ñÇâÍÕ×±À¦Ç¦¹äÊçÁñ±ûÑ÷³®ÌãÈ®¹ªÖçÔåÖëºÖ¼ÕµìÄ¼µ¢µ¸ÂªÂÂÖ¶Å°¶éÓ¨½Æ·§½Ê¿å¸à¾¥ÃåÀ®ÈŞ½ÁµÊËóÅ¥¹×¹¢µŞĞ¸¼µÔîÔÈ¸ëÔèÔäÎ³·ĞÈĞ³ë¶ôË¸Ğá°È°¾Éİ×¾¶°ÌºÍ©É°ĞºÃ§ÆºÊáÉ¼ÎîÖÉÊßÓ¬Çêµ·ÁòÏÛ½ÀÂÙ»¦¿õ±òÑ¿ÀêÌ¼ßÖÌèÊîÂÜĞÚĞÈ¿ú°³Ì¶Æé¼ñÕü³ÎÎ®ÎĞÌÏÏ¾ËİÁÛÄğÒğãµÄºÑÃ½ë¸«»À×ØÓÓË»¼ËĞúÈØÉ¾Ó£ËÅÎËÉÒ°Ó²Ï·óÀ½ĞÓÒ±ÄÓ±ÓÂ§ÄôÍñÔë¼Ú÷¢ÁâÕµÄäÖ¨ÇŞÀ¿Ëè±üÊ¸²¸ÖÄËÔĞ®¸×ÈàÄåÑ±ÀÂÉÎÌ±ÖüÃÙëüÆ§ÂûÇ¶ÅÏËöµúÉ¬ëÊ±Ä½óß¶Ğñ¾÷Ïº²¾Æ¡ÇÜÔæÅ»ÂæÍ¹Ï¨ÉÑ°¼ÊêÍÍÌÅ½½×ÆÅé¼¬ÏğÁû¼îÀÑÃÈ¾ÚÇÎÆ²ËÚ·à¹¶Âì¼óÌû¼åÂÆ´ØÀâÄÅİºÊûÌÌÍÜÁæ´õ´ĞÏøÀ¤Àª»äÌäÕ§°ê½ÃÍ÷°Ï¹£²Ş×Á¼¥¿ßÁ²Â®ÅßÉë´Â¶ó¸Í¿¶´¸Ë¨½°ÎÃ°õÄõ²Ñ´ÁÙ÷½¦¸Æ½¸ÕÃÃĞ»íÁ×ÓØÕ°Â­Áğµ¿ºû¼ğÃì¾ìÃõÌ­ÉôÏâ¿»»ÂÅ¿±Á¾½Ïù×Ã×ÇÊÈº³¿¸ÇÍÇÌ¿Ä²ÛÕ¤ÌÊÍÇÑ¬Äµ×º»²Àæ·¾Ìé±¹Ä¡õâÖâÈÛÖ¿ÂÈÒïÁİÊü¸¬ÄÀÇÏÖàâÖ²×µ¡ŞÈÁü°±´£¿øÄ´Åæ´§Õ¸¾Ï¿ÑÇ¢ÍÙ³÷Ö©ÌµÍà¼í²õĞ·¾éÇæ°Ì²ù¶ÛÏ»Ã¥»¡×¶¾¾¸Ü¿ÔÎÜÊãº·ÃÒ»Ş´×¾âØ²º¾³Ş»«ÅÇÏõÔí¶æàÂ±·Ñ¥Îæ´¯¿Á»à´ê½´ÁŞéÜ½¶Ì¦Éâ¶ĞÏÏ¿êÎÉĞöÁÈ¾¤²ÚØÔ»±°ÇĞõ°ÅÌë»¾ÕÀÏüÒØ²íÇÑ¶üÈÍ±ï·ŞĞÆ´¾ÔÁ°¯±ô»ûÎëÌŞÀéµí»£ÂàÖºÕå°°°âË©×çÅ³Àç³ÑÅ¡º¥°íÈù½·Îµ¿ôÕ»Ş±°¹ÆÙÔü¹Óß´ÍÎÎ¡¾ÎÀğÕŞ°ÃĞôÕîÂÁµÓÊÑÆöÀãÚåÍİ·ã¿½¶ßÎ­ôæÖÏÒÈ°ĞÎß±èº¿»ÏµèºùÂË²ÇØ°°ùàÍº´·õñ«ÏıÈïºæÔşÂ¸ÓÜ»È¿¥É×Õ¢·®¹¸ÎÁ¹½ÌêìÅÄçÔÉÔßàÖÉÅÑ³Ãö²ô¶èÔûÍÖßäö®½ÑìôÀß³ÀÀÙ¹è´¶òğÊÃÊºÍÊËíÈ×Ç¯¿Ğ¹ëÌòµÅ¸¤ÊÁÅ¹Îà³Ú½ÄÍ±ÔÍÊí³ºĞâ³íÅØÅ¸æÒÅ§ÂâËëĞÏ²óÊïÓçÉ¸ÚË±Ô²ş¸Ø¶êßëÓ«ÊşÈÁ´ÛØ¬áãËîÀìôáÇº¿ğÌ´·ÍÍÔ¾æÓ©óİÅùÀÓğ¯Ëâ²ºÆ¹×ÄÕ±ÈìÉ¦ËñÄüÃá°ªÅëÑÙãåÓ½ÆÔÄíã²ÄÆ´·°ÀÅìµª³ûÑß´éğĞÏ¬¹ÁéÏÆşØÒÃªÅÒÒ¾Áßã¾»åÀùÈäëÈÁÃËÖÑí¸ÈÈµ¸íÄ¢¿¬Ğ¿½Íá£°ı×á¾ó·Ì³úÔÜö¨´ñßº¶Õ´ÑÎ¦ÑêÀş×ÑÌ»°è³È×¸ÓÙ¿ûº¨ÀÅô¤ºÌèµÍïÒ¸Á»Á¤ÉÓ¸áé­¼ëğÄéÙÇË°ÊÈ¬ÅÙÍÉÑèÂøŞÖÖãóïµóçÔÈß½ÈËôÑÑÙËÕ¥µï¼ÏÀÒ¿«Ì£µâÄëÀŞ¾ÔÑúË±µğ¿¢äö²äÃÓÌñõÎÎÏº©¸òÍ«Æ°ÇÛ³Ó¶åÁÊÂ±µÕ÷ŞµëÃêßóÑ´îíÃó²³¹¿ÏÚ¹¯ÏÑó¬öù¶ï·¤Å÷ÂÍ²çó°ÄìçÍ°ú±Ã¼ØÉû±ñõåÅÈõïÁ­½§òùÆêÔ¯»ÁŞà½Õ²öÁşĞ¨Àóó¡ÒÙçÖèëÒ´Ô§ÂÕ¿ÀÎÍõËÓ»óÏ·¡ÉÄ¸şÁÀòÚÅºĞ«Ò¬¶ÆÅ¢ó¦ÃÊÈ³ÕºÕá¿ş°ö±º¹ô±îÓ¼ÑìÖûÇ­ÀÜÖÑ½æ¿æ¶âÊ­Â¨µà¾Ä×»»×ÔÅ±¢ò½ÁÇòßÕøé¹Â¦ÔéÌÂÜÔ°ğÕÁá«¾ÊÑ¢çèâÉÍ®òÑêÇº¸ñÉò¾¿Ùò¼¶»Á¡òòòÇ¼ÔÑâ°ÒéÅ¸ÑÓ§ÇÂÃäÅ±ÄÙ¿·ÈÒÀÔÈòĞï´»öê¶§ÃÌÅ´Íãíïëç¸äñ®¾Âë¹Öô¹¡Óó²òÇùÄûêşê¼¸Ì»çìªÒ¨İïÍÒ²êÀÆ²t»şÉÖëıÈşµ§ÁÍÑÁîõÂáâ¬×ÂÕ¡ÉŞàÒ×Òè¾¿èäÌ²¤¶ÚòÈº»é»·¯ÅğÉ»¸İàÚÏÇÒ¼ñÃÁóÄèÏ³ÆèÑäï±±ìóÔ±ÍÌÜÜñÈ¿¾ÁÊòÃøÙìÃ­ÜîÄ÷ÒŞ°ÆéİÜùôïïøó¨İ©ïõÆâ";
	return chineseTable;
}
static int getRandomValue(const int minValue, const int maxValue)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(minValue,maxValue);
	return dis(gen);
}
struct SampleStyle
{
	std::string font;
	SampleStyle(const std::string& _font) :font(_font){}
};
struct SampleDesc
{
	wchar_t txtChar;
	cv::Mat image;
};
static cv::Mat addSaltNoise(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
	cv::Mat saltPepperNoise = cv::Mat::zeros(resultImg.rows, resultImg.cols, CV_8UC1);
	cv::randu(saltPepperNoise, 0, 255);
	const cv::Mat black = saltPepperNoise < 10;
	const cv::Mat white = saltPepperNoise > 245;
	resultImg.setTo(255, white);
	resultImg.setTo(0, black);
	return resultImg;
}
static cv::Mat addGaussianNoise(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
	cv::Mat noise = cv::Mat::zeros(resultImg.size(), CV_8UC1);
	cv::randn(noise, 8, 30);
	cv::add(resultImg, noise, resultImg);
	return resultImg;
}
static cv::Mat addGaussianSmooth(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
	cv::GaussianBlur(resultImg, resultImg, cv::Size(3, 3), 0.1f);
	return resultImg;
}
static cv::Mat horizontalShiftLeft(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 3);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < result.rows; y++)
	{
		uchar* lineData = result.data + y*result.cols;
		memcpy(lineData, lineData + shiftDist, result.cols - shiftDist);
		memset(lineData + (result.cols - shiftDist), bgColor, shiftDist);
	}
	return result;
}
static cv::Mat horizontalShiftRight(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 3);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < result.rows; y++)
	{
		uchar* lineData = result.data + y*result.cols;
		memcpy(lineData + shiftDist, lineData, result.cols - shiftDist);
		memset(lineData, bgColor, shiftDist);
	}
	return result;
}
static cv::Mat verticalShiftUp(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 3);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < result.rows - shiftDist; y++)
	{
		const uchar* srcLineData = result.data + (y + shiftDist)*result.cols;
		uchar* dstLineData = result.data + y*result.cols;
		memcpy(dstLineData, srcLineData, result.cols);
	}
	for (int y = result.rows-shiftDist; y < result.rows; y++)
	{
		uchar* dstLineData = result.data + y*result.cols;
		memset(dstLineData, bgColor, result.cols);
	}
	return result;
}
static cv::Mat verticalShiftDown(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 3);
	cv::Mat result = grayImg.clone();
	for (int y = result.rows - shiftDist; y >= shiftDist; y--)
	{
		const uchar* srcLineData = result.data + (y - shiftDist)*result.cols;
		uchar* dstLineData = result.data + y*result.cols;
		memcpy(dstLineData, srcLineData, result.cols);
	}
	for (int y = 0; y < shiftDist; y++)
	{
		uchar* dstLineData = result.data + y*result.cols;
		memset(dstLineData, bgColor, result.cols);
	}
	return result;
}
static cv::Mat addSkew(const cv::Mat& grayImg)
{
	cv::Mat result = grayImg.clone();
	const int degree = getRandomValue(-20, 20);
	const cv::Point center(result.cols / 2, result.rows / 2);
	const cv::Mat rotMatS = cv::getRotationMatrix2D(center, degree, 1.0);
	warpAffine(result, result, rotMatS, result.size(), 1, 0, bgColor);
	return result;
}
static cv::Mat perTransform(const cv::Mat& grayImg)
{
	cv::Mat result = cv::Mat(grayImg.size(), CV_8UC1);
	result.setTo(bgColor);
	const int imgWidth = result.cols;
	const int imgHeight = result.rows;	
	std::vector<cv::Point2f> corners(4);
	corners[0] = cv::Point2f(0, 0);
	corners[1] = cv::Point2f(imgWidth - 1, 0);
	corners[2] = cv::Point2f(0, imgHeight - 1);
	corners[3] = cv::Point2f(imgWidth - 1, imgHeight - 1);
	//TODO : random it
	std::vector<cv::Point2f> corners_trans(4);
	corners_trans[0] = cv::Point2f(0, 0);
	corners_trans[1] = cv::Point2f(imgWidth-1, 0);
	corners_trans[2] = cv::Point2f(0, imgHeight - 1);
	corners_trans[3] = cv::Point2f(imgWidth-1, imgHeight - 1);
	//action
	cv::Mat transform = cv::getPerspectiveTransform(corners, corners_trans);
	std::vector<cv::Point2f> ponits, points_trans;
	for (int i = 0; i < imgHeight; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			ponits.push_back(cv::Point2f(j, i));
		}
	}
	cv::perspectiveTransform(ponits, points_trans, transform);
	int count = 0;
	for (int i = 0; i < imgHeight; i++)
	{
		const uchar* p = grayImg.ptr<uchar>(i);
		for (int j = 0; j < imgWidth; j++)
		{
			int y = points_trans[count].y;
			int x = points_trans[count].x;
			if (y >= 0 && y < imgHeight)
			{
				uchar* t = result.ptr<uchar>(y);
				t[x] = p[j];
				count++;
			}
		}
	}
	return result;
}
static std::vector<SampleDesc> genSample(const wchar_t txtChar, const SampleStyle style, const int standardSize,const int singleParm,const int multiParam)
{
	std::vector<SampleDesc> result;
	const int srcSize = 86;
	SampleGenetator paiter(style.font, srcSize);
	//src
	const auto srcImg = paiter.genSample(txtChar, bgColor, fgColor);
	//smooth
	cv::Mat smoothedImg;
	cv::GaussianBlur(srcImg, smoothedImg, cv::Size(3, 3), 1.0f);
	//resize
	cv::Mat standardImg;
	if (!smoothedImg.data)
	{
		std::cout << "style : {" << style.font << "}" << std::endl;
		std::cout << "lost char : txtChar = " << txtChar << ",width=" << smoothedImg.cols << ",height=" << smoothedImg.rows << std::endl;
		return result;
	}
	else
	{
		cv::resize(smoothedImg, standardImg, cv::Size(standardSize, standardSize), 0.0, 0.0, cv::INTER_AREA);
	}
	//process chain
	//////////////////////////////////////////////////////////////////////////
	using procFuncType = std::function<cv::Mat(const cv::Mat&)>;
	std::vector<procFuncType> procFuncs{
		addSaltNoise,
		addGaussianNoise,
		addGaussianSmooth,
		horizontalShiftLeft,
		horizontalShiftRight,
		verticalShiftUp,
		verticalShiftDown,
		addSkew
		//perTransform
	};
	//////////////////////////////////////////////////////////////////////////
	//standard
	SampleDesc sample;
	sample.txtChar = txtChar;
	sample.image = standardImg;
	result.push_back(sample);
	//////////////////////////////////////////////////////////////////////////
	//single
	const int singleSample = singleParm;
	for (int i = 0; i < singleSample; i++)
	{
		for (auto& func : procFuncs)
		{
			sample.image = func(standardImg);
			result.push_back(sample);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//random
	const int chainSamples = multiParam;
	for (int i = 0; i < chainSamples;i++)
	{
		const int chainLen = 2;
		auto img = standardImg.clone();
		for (int j = 0; j < chainLen; j++)
		{
			const int curIdx = getRandomValue(0, procFuncs.size()-1);
			auto& func = procFuncs[curIdx];
			img = func(img);
		}
		sample.image = img;
		result.push_back(sample);
	}
	return result;
}
//copied from caffe [https://github.com/BVLC/caffe/blob/c7ee2615a8df2dedb408ff9c2c842e5f4f42a310/include/caffe/util/format.hpp]
static inline std::string format_int(int n, int numberOfLeadingZeros = 0) {
	std::ostringstream s;
	s << std::setw(numberOfLeadingZeros) << std::setfill('0') << n;
	return s.str();
}
static void genSamples(const std::wstring& charList, const std::string& trainFilePath, const std::string& validateFilePath,const std::string& reportFilePath)
{
	const int standardSize = 32;
	const auto styles = std::vector<SampleStyle>{
		SampleStyle("Î¢ÈíÕıºÚÌå.ttf"),
		SampleStyle("·½ÕıĞÂÊéËÎ¼òÌå.ttf")
	};

	std::ofstream ofsReport(reportFilePath);

	// leveldb
	leveldb::Options options;
	options.error_if_exists = true;
	options.create_if_missing = true;
	options.write_buffer_size = 268435456;
	leveldb::Status status;
	//train
	leveldb::DB* trainDb = nullptr;
	status = leveldb::DB::Open(
		options, trainFilePath, &trainDb);
	if (!status.ok())
	{
		std::cerr << "failed to open levelDB , path = " << trainFilePath << std::endl;
		return;
	}
	SCOPEEXIT(delete trainDb;);
	leveldb::WriteBatch* trainBatch = new leveldb::WriteBatch();
	SCOPEEXIT(delete trainBatch;);
	//validate
	leveldb::DB* validateDb = nullptr;
	status = leveldb::DB::Open(
		options, validateFilePath, &validateDb);
	if (!status.ok())
	{
		std::cerr << "failed to open levelDB , path = " << validateFilePath << std::endl;
		return;
	}
	SCOPEEXIT(delete validateDb;);
	leveldb::WriteBatch* validateBatch = new leveldb::WriteBatch();
	SCOPEEXIT(delete validateBatch;);
	//
	const int batchSize = 3000;
	int trainSampleIdx = 0;
	int validateSampleIdx = 0;
	SCOPEEXIT(if(trainSampleIdx % batchSize != 0){trainDb->Write(leveldb::WriteOptions(), trainBatch);});
	SCOPEEXIT(if (validateSampleIdx % batchSize != 0){ validateDb->Write(leveldb::WriteOptions(), validateBatch); });

	//////////////////////////////////////////////////////////////////////////
	std::cout << "---------------------------" << std::endl;
	std::cout << "generating samples ..." << std::endl;
	std::vector<SampleDesc> train_samples;
	std::vector<SampleDesc> validate_samples;
	std::map<wchar_t, int> train_statistics;
	std::map<wchar_t, int> validate_statistics;
	const int train_single_param = 20;
	const int train_multi_param = 40;
	const int validate_single_param = 6;
	const int validate_multi_param = 15;
	//gen samples
	if (charList.size() < 10)
	{
		for (const auto& txtChar : charList)
		{
			//asyn
			for (const auto& style : styles)
			{
				//train
				const auto trainSampleSet = genSample(txtChar, style, standardSize, train_single_param, train_multi_param);
				std::copy(trainSampleSet.cbegin(), trainSampleSet.cend(), std::back_inserter(train_samples));				
				//validate
				const auto validateSampleSet = genSample(txtChar, style, standardSize, validate_single_param, validate_multi_param);
				std::copy(validateSampleSet.cbegin(), validateSampleSet.cend(), std::back_inserter(validate_samples));
				train_statistics[txtChar] += trainSampleSet.size();
				validate_statistics[txtChar] += validateSampleSet.size();
			}
		}	
	}
	else
	{
		int idx = 0;
		auto synFetchCharFunc = [&idx,&charList](wchar_t& txtChar)->bool{
			if (idx >= charList.size())
			{
				return false;
			}
			txtChar = charList[idx];
			idx++;
			return true;
		};
		std::vector<std::thread> threads(4);
		std::mutex mtx;
		for (size_t i = 0; i < threads.size(); i++)
		{
			threads[i] = std::thread([&styles, &synFetchCharFunc, &standardSize, &mtx, &train_samples, &validate_samples, &train_statistics, &validate_statistics,
				&train_single_param, &train_multi_param, &validate_single_param, &validate_multi_param]{
				while (true)
				{
					wchar_t txtChar = 0;
					//syn block
					{
						std::lock_guard<std::mutex> locker(mtx);
						const bool isOK = synFetchCharFunc(txtChar);
						if (!isOK)
						{
							break;
						}
					}					
					std::vector<SampleDesc> trainSampleSet;
					std::vector<SampleDesc> validateSampleSet;
					//asyn block
					{
						for (const auto& style : styles)
						{
							//train
							trainSampleSet = genSample(txtChar, style, standardSize, train_single_param, train_multi_param);
							//validate
							validateSampleSet = genSample(txtChar, style, standardSize, validate_single_param, validate_multi_param);
						}						
					}
					//syn block
					{
						std::lock_guard<std::mutex> locker(mtx);
						std::copy(trainSampleSet.cbegin(), trainSampleSet.cend(), std::back_inserter(train_samples));
						std::copy(validateSampleSet.cbegin(), validateSampleSet.cend(), std::back_inserter(validate_samples));
						train_statistics[txtChar] += trainSampleSet.size();
						validate_statistics[txtChar] += validateSampleSet.size();
					}
				}			
			});
		}
		for (size_t i = 0; i < threads.size(); i++)
		{
			threads[i].join();
		}
	}
	std::cout << "generate samples done." << std::endl;
	std::cout << "train sample set : " << train_samples.size() << std::endl;
	std::cout << "validate sample set : " << validate_samples.size() << std::endl;
	ofsReport << "train sample set : " << train_samples.size() << std::endl;
	ofsReport << "validate sample set : " << validate_samples.size() << std::endl;
	ofsReport << "---------------------------" << std::endl;
	ofsReport << "train total char count : " << train_statistics.size() << std::endl;
	ofsReport << "train details : " << std::endl;
	for (const auto item : train_statistics)
	{
		ofsReport << item.first << "\t" << item.second << std::endl;
	}
	ofsReport << "---------------------------" << std::endl;
	ofsReport << "validate total char count : " << validate_statistics.size() << std::endl;
	ofsReport << "validate details : " << std::endl;
	for (const auto item : validate_statistics)
	{
		ofsReport << item.first << "\t" << item.second << std::endl;
	}
	std::cout << "---------------------------" << std::endl;
	std::cout << "shuffling samples ..." << std::endl;
	//shuffle
	const auto randSeed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(train_samples.begin(), train_samples.end(), std::default_random_engine(randSeed));
	std::shuffle(validate_samples.begin(), validate_samples.end(), std::default_random_engine(randSeed));
	std::cout << "shuffle samples done." << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "writing samples ..." << std::endl;
	//dump
	//commmon
	//dump func
	auto dumpData = [&standardSize, &batchSize](const SampleDesc& sample, leveldb::DB*& db, leveldb::WriteBatch*& batch, const int total, int& curSampleIdx){
		//details
		const auto& img(sample.image);
		std::string key_str = format_int(curSampleIdx, 8);
		std::string value;
		caffe::Datum datum;
		datum.set_channels(1);
		datum.set_height(standardSize);
		datum.set_width(standardSize);
		datum.set_label(sample.txtChar);
		datum.set_data(img.data, img.rows*img.cols);
		datum.SerializeToString(&value);
		batch->Put(key_str, value);
		//batch write
		curSampleIdx++;
		if (curSampleIdx % batchSize == 0)
		{
			db->Write(leveldb::WriteOptions(), batch);
			delete batch;
			batch = new leveldb::WriteBatch();
			std::cout << "current text : " << sample.txtChar << std::endl;
			std::cout << "progress : " << curSampleIdx << "/" << total << std::endl;			
		}		
	};
	//train set
	for (const auto& sample : train_samples)
	{
		dumpData(sample, trainDb, trainBatch, train_samples.size(), trainSampleIdx);
	}
	//validate set
	for (const auto& sample : validate_samples)
	{
		dumpData(sample, validateDb, validateBatch, validate_samples.size(), validateSampleIdx);
	}
	std::cout << "write done!" << std::endl;
	std::cout << "---------------------------\n\n"<< std::endl;
}
static void example()
{
	const int srcSize = 86;
	const int standardSize = 32;
	const auto font = R"(·½ÕıĞÂÊéËÎ¼òÌå.ttf)";
	SampleGenetator paiter(font, srcSize);
	const auto chineseTable = getChineseTable();
	while (true)
	{
		const auto txtChar = chineseTable[getRandomValue(0, chineseTable.size()-1)];
		const auto srcImg = paiter.genSample(txtChar, bgColor,fgColor);
		cv::Mat smoothedImg;
		cv::GaussianBlur(srcImg, smoothedImg, cv::Size(3, 3), 1.0f);
		cv::Mat standardImg;
		cv::resize(smoothedImg, standardImg, cv::Size(standardSize, standardSize), 0.0, 0.0, cv::INTER_AREA);
		cv::destroyAllWindows();
		cv::imshow("srcImg", srcImg);
		cv::imshow("smoothedImg", smoothedImg);
		cv::imshow("standardImg", standardImg);
		const auto key = cv::waitKey(0);
		if (key == 27)
		{
			break;
		}
	}
}
int main()
{
	//example();
	//
	system("del /q train.data");
	system("del /q test.data");
	genSamples(getChineseTable(), "train.data","test.data","report.txt");
	//parserSampleData("Î¢ÈíÕıºÚÌå.data");
	return 0;
}