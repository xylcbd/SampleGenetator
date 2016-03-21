#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <random>
#include "SampleGenetator.h"

static std::wstring getChineseTable()
{
	static const std::wstring chineseTable = L"µÄÒ»ÊÇ²»ÁËÔÚÈËÓÐÎÒËûÕâ¸öÃÇÖÐÀ´ÉÏ´óÎªºÍ¹úµØµ½ÒÔËµÊ±Òª¾Í³ö»á¿ÉÒ²Äã¶ÔÉúÄÜ¶ø×ÓÄÇµÃÓÚ×ÅÏÂ×ÔÖ®Äê¹ý·¢ºó×÷ÀïÓÃµÀÐÐËùÈ»¼ÒÖÖÊÂ³É·½¶à¾­Ã´È¥·¨Ñ§Èç¶¼Í¬ÏÖµ±Ã»¶¯ÃæÆð¿´¶¨Ìì·Ö»¹½øºÃÐ¡²¿ÆäÐ©Ö÷ÑùÀíÐÄËý±¾Ç°¿ªµ«ÒòÖ»´ÓÏëÊµÈÕ¾üÕßÒâÎÞÁ¦ËüÓë³¤°Ñ»úÊ®ÃñµÚ¹«´ËÒÑ¹¤Ê¹ÇéÃ÷ÐÔÖªÈ«ÈýÓÖ¹ØµãÕýÒµÍâ½«Á½¸ß¼äÓÉÎÊºÜ×îÖØ²¢ÎïÊÖÓ¦Õ½ÏòÍ·ÎÄÌåÕþÃÀÏà¼û±»ÀûÊ²¶þµÈ²ú»òÐÂ¼ºÖÆÉí¹û¼ÓÎ÷Ë¹ÔÂ»°ºÏ»ØÌØ´úÄÚÐÅ±í»¯ÀÏ¸øÊÀÎ»´Î¶ÈÃÅÈÎ³£ÏÈº£Í¨½Ì¶ùÔ­¶«ÉùÌáÁ¢¼°±ÈÔ±½âË®ÃûÕæÂÛ´¦×ßÒå¸÷Èë¼¸¿ÚÈÏÌõÆ½ÏµÆøÌâ»î¶û¸ü±ð´òÅ®±äËÄÉñ×ÜºÎµçÊý°²ÉÙ±¨²Å½á·´ÊÜÄ¿Ì«Á¿ÔÙ¸Ð½¨Îñ×ö½Ó±Ø³¡¼þ¼Æ¹ÜÆÚÊÐÖ±µÂ×ÊÃüÉ½½ðÖ¸¿ËÐíÍ³Çø±£ÖÁ¶ÓÐÎÉç±ã¿Õ¾öÖÎÕ¹Âí¿ÆË¾Îå»ùÑÛÊé·ÇÔòÌý°×È´½ç´ï¹â·ÅÇ¿¼´ÏñÇÒÄÑÈ¨Ë¼ÍõÏóÍêÉèÊ½É«Â·¼ÇÄÏÆ·×¡¸æÀàÇó¾Ý³Ì±±±ßËÀÕÅ¸Ã½»¹æÍòÈ¡À­¸ñÍû¾õÊõÁì¹²È·´«Ê¦¹ÛÇå½ñÇÐÔºÈÃÊ¶ºò´øµ¼ÕùÔËÐ¦·É·ç²½¸ÄÊÕ¸ù¸ÉÔìÑÔÁª³Ö×éÃ¿¼Ã³µÇ×¼«ÁÖ·þ¿ì°ìÒéÍùÔªÓ¢Ê¿Ö¤½üÊ§×ª·òÁî×¼²¼Ê¼ÔõÄØ´æÎ´Ô¶½ÐÌ¨µ¥Ó°¾ßÂÞ×Ö°®»÷Á÷±¸±øÁ¬µ÷ÉîÉÌËãÖÊÍÅ¼¯°ÙÐè¼Û»¨µ³»ª³ÇÊ¯¼¶Õû¸®Àë¿öÑÇÇë¼¼¼ÊÔ¼Ê¾¸´²¡Ï¢¾¿ÏßËÆ¹Ù»ð¶Ï¾«ÂúÖ§ÊÓÏûÔ½Æ÷ÈÝÕÕÐë¾ÅÔöÑÐÐ´³ÆÆó°Ë¹¦Âð°üÆ¬Ê·Î¯ºõ²éÇáÒ×ÔçÔø³ýÅ©ÕÒ×°¹ãÏÔ°É°¢Àî±êÌ¸³ÔÍ¼ÄîÁùÒýÀúÊ×Ò½¾ÖÍ»×¨·ÑºÅ¾¡ÁíÖÜ½Ï×¢Óï½ö¿¼ÂäÇàËæÑ¡ÁÐÎäºìÏìËäÍÆÊÆ²ÎÏ£¹ÅÖÚ¹¹·¿°ë½ÚÍÁÍ¶Ä³°¸ºÚÎ¬¸ï»®µÐÖÂ³ÂÂÉ×ãÌ¬»¤ÆßÐËÅÉº¢ÑéÔðÓªÐÇ¹»ÕÂÒô¸úÖ¾µ×Õ¾ÑÏ°ÍÀý·À×å¹©Ð§ÐøÊ©Áô½²ÐÍÁÏÖÕ´ð½ô»Æ¾øÆæ²ìÄ¸¾©¶ÎÒÀÅúÈºÏî¹Ê°´ºÓÃ×Î§½­Ö¯º¦¶·Ë«¾³¿Í¼Í²É¾ÙÉ±¹¥¸¸ËÕÃÜµÍ³¯ÓÑËßÖ¹Ï¸Ô¸Ç§ÖµÈÔÄÐÇ®ÆÆÍøÈÈÖúµ¹ÓýÊô×øµÛÏÞ´¬Á³Ö°ËÙ¿ÌÀÖ·ñ¸ÕÍþÃ«×´ÂÊÉõ¶ÀÇò°ãÆÕÅÂµ¯Ð£¿à´´¼Ù¾Ã´í³ÐÓ¡ÍíÀ¼ÊÔ¹ÉÄÃÄÔÔ¤Ë­ÒæÑôÈôÄÄÎ¢Äá¼ÌËÍ¼±Ñª¾ªÉËËØÒ©ÊÊ²¨Ò¹Ê¡³õÏ²ÎÀÔ´Ê³ÏÕ´ýÊöÂ½Ï°ÖÃ¾ÓÀÍ²Æ»·ÅÅ¸£ÄÉ»¶À×¾¯»ñÄ£³ä¸ºÔÆÍ£Ä¾ÓÎÁúÊ÷ÒÉ²ãÀäÖÞ³åÉäÂÔ·¶¾¹¾äÊÒÒì¼¤ºº´å¹þ²ßÑÝ¼ò¿¨×ïÅÐµ£ÖÝ¾²ÍË¼ÈÒÂÄú×Ú»ýÓàÍ´¼ì²î¸»ÁéÐ­½ÇÕ¼ÅäÕ÷ÐÞÆ¤»ÓÊ¤½µ½×Éó³Á¼áÉÆÂèÁõ¶Á°¡³¬ÃâÑ¹ÒøÂò»ÊÑøÒÁ»³Ö´¸±ÂÒ¿¹·¸×·°ïÐû·ðËêº½ÓÅ¹ÖÏãÖøÌïÌú¿ØË°×óÓÒ·Ý´©ÒÕ±³Õó²Ý½Å¸Å¶ñ¿é¶Ù¸ÒÊØ¾ÆµºÑëÍÐ»§ÁÒÑó¸çË÷ºú¿î¿¿ÆÀ°æ±¦×ùÊÍ¾°¹ËµÜµÇ»õ»¥¸¶²®ÂýÅ·»»ÎÅÎ£Ã¦ºË°µ½ã½é»µÌÖÀöÁ¼ÐòÉý¼àÁÙÁÁÂ¶ÓÀºôÎ¶Ò°¼ÜÓòÉ³µôÀ¨½¢ÓãÔÓÎóÍå¼ª¼õ±à³þ¿Ï²â°ÜÎÝÅÜÃÎÉ¢ÎÂÀ§½£½¥·â¾È¹óÇ¹È±Â¥ÏØÉÐºÁÒÆÄïÅó»­°àÖÇÒà¶ú¶÷¶ÌÕÆ¿ÖÒÅ¹ÌÏ¯ËÉÃØÐ»Â³Óö¿µÂÇÐÒ¾ùÏúÖÓÊ«²Ø¸Ï¾çÆ±Ëðºö¾ÞÅÚ¾É¶ËÌ½ºþÂ¼Ò¶´ºÏç¸½ÎüÓèÀñ¸ÛÓêÑ½°åÍ¥¸¾¹é¾¦·¹¶îº¬Ë³ÊäÒ¡ÕÐ»éÍÑ²¹Î½¶½¶¾ÓÍÁÆÂÃÔó²ÄÃðÖðÄª±ÊÍöÏÊ´ÊÊ¥ÔñÑ°³§Ë¯²©ÀÕÑÌÊÚÅµÂ×°¶°ÂÌÆÂô¶íÕ¨ÔØÂå½¡ÌÃÅÔ¹¬ºÈ½è¾ý½ûÒõÔ°Ä±ËÎ±Ü×¥ÈÙ¹ÃËïÌÓÑÀÊøÌø¶¥ÓñÕòÑ©ÎçÁ·Ò¯ÆÈÆªÈâ×ì¹Ý±é·²´¡¶´¾íÌ¹Å£ÄþÖ½ÖîÑµË½×¯×æË¿·­±©É­ËþÄ¬ÎÕÏ·ÒþÊì¹Ç·ÃÈõÃÉ¸èµê¹íÈíµäÓûÈø»ïÔâÅÌ°ÖÀ©¸ÇÅªÐÛÎÈÍüÒÚ´ÌÓµÍ½Ä·ÑîÆëÈüÈ¤Çúµ¶´²Ó­±ùÐéÍæÎö´°ÐÑÆÞÍ¸¹ºÌæÈûÅ¬ÐÝ»¢ÑïÍ¾ÇÖÐÌÂÌÐÖÑ¸Ì×Ã³±ÏÎ¨¹ÈÂÖ¿â¼£ÓÈ¾º½Ö´ÙÑÓÕðÆú¼×Î°Âé´¨Éê»ºÇ±ÉÁÊÛµÆÕëÕÜÂçµÖÖì°£±§¹ÄÖ²´¿ÏÄÈÌÒ³½ÜÖþÕÛÖ£±´×ðÎâÐã»ì³¼ÑÅÕñÈ¾Ê¢Å­ÎèÔ²¸ã¿ñ´ëÐÕ²ÐÇïÅàÃÔ³Ï¿íÓîÃÍ°ÚÃ·»ÙÉìÄ¦ÃËÄ©ÄË±¯ÅÄ¶¡ÕÔÓ²Âó½¯²Ù×è¶©²Ê³éÔÞÄ§·×ÑØº°Î¥ÃÃÀË»ã±Ò·áÀ¶ÊâÏ××ÀÀ²ÍßÀ³Ô®Òë¶áÆûÉÕ¾à²ÃÆ«·ûÓÂ´¥¿Î¾´¿Þ¶®Ç½ÕÙÏ®·£ÏÀÌü°ÝÇÉ²àº«Ã°Õ®ÂüÈÚ¹ßÏí´÷Í¯ÓÌ³Ë¹Ò½±ÉÜºñ×ÝÕÏÑ¶Éæ³¹¿¯ÕÉ±¬ÎÚÒÛÃèÏ´Âê»¼Ãî¾µ³ª·³Ç©ÏÉ±ËÖ¢·ÂÇãÅÆÏÝÄñºäÔÛ²Ë±Õ·ÜÇì³·Àá²è¼²Ôµ²¥ÀÊ¶ÅÄÌ¼¾µ¤¹·Î²ÒÇÍµ±¼Öé³æ×¤¿×ÒË°¬ÇÅµ­ÒíºÞ·±º®°éÌ¾µ©Óú³±Á¸Ëõ°Õ¾Û¾¶Ç¡Ìô´ü»Ò²¶ÐìÕäÄ»Ó³ÁÑÌ©¸ôÆô¼âÖÒÀÛÑ×ÔÝ¹À·º»Ä³¥ºá¾ÜÈðÒä¹Â±ÇÄÖÑò´ôÀ÷ºâ°ûÁãÇîÉáÂëºÕÆÅ»êÔÖºéÍÈµ¨½òË×±çÐØÏþ¾¢ÈÊÆ¶Å¼¼­°î»ÖÀµÈ¦ÃþÑöÈó¶ÑÅöÍ§ÉÔ³ÙÁ¾·Ï¾»Ð×Êð±ÚÓù·îÐý¶¬¿óÌ§µ°³¿·ü´µ¼¦±¶ºýÇØ¶Ü±­×âÆï·¦Â¡ÕïÅ«ÉãÉ¥ÎÛ¶ÉÆì¸ÊÄÍÆ¾ÔúÇÀÐ÷´Ö¼çÁº»Ã·Æ½ÔËéÖæÊåÑÒµ´×ÛÅÀºÉÏ¤µÙ·µ¾®×³±¡ÇÄÉ¨Ãô°­Ö³ÏêÃ¬»ôÔÊ·ùÈöÊ£¿­¿ÅÂîÉÍÒº·¬ÏäÌùÂþËáÀÉÑüÊæÃ¼ÓÇ¸¡ÐÁÁµ²ÍÏÅÍ¦Àø´ÇËÒ¼üÎé·å³ß×òÀè±²¹áÕì»¬È¯³çÈÅÏÜÈÆÇ÷´ÈÇÇÔÄº¹Ö¦ÍÏÄ«Ð²²å¼ýÀ°Äà·ÛÊÏÅí°ÎÆ­·ï»ÛÃ½Åå·ßÆËÁäÇýÏ§ÑÚºÀ¼æÔ¾Ê¬ËàÅÁÊ»±¤½ìÐÀ»Ý²á´¢Æ®É£ÏÐ²Ò½à×Ù²ª±öÆµ³ðÄ¥µÝÐ°×²Äâ¹ö×àÑ²ÑÕ¼Á¼¨¹±·èÆÂÇÆ½ØÈ¼½¹µîÎ±ÁøËø±ÆÆÄ»èÈ°³ÊËÑÇÚ½ä¼ÝÆ¯Òû²Ü¶ä×ÐÈáÁ©ÃÏ¸¯Ó×¼ù¼®ÄÁÁ¹Éü¼ÑÄÈÅ¨·¼¸åÖñ¸¹µøÂß´¹×ñÂöÃ²°ØÓü²ÂÁ¯»óÌÕÊÞÕÊÊÎ´û²ýÐðÌÉ¸Ö¹µ¼Ä·öÆÌµËÊÙ¾åÑ¯ÌÀµÁ·Ê³¢´Ò»ÔÄÎ¿ÛÍ¢°Ä¶­Ç¨ÄýÎ¿ÑáÔàÌÚÓÄÔ¹Ð¬¶ªÂñÈªÓ¿Ï½¶ã½ú×Ï¼èÎº»Å×£ÓÊÍÂºÝ¼øÐµÒ§ÁÚ³à¼·ÍäÒÎÅã¸î½ÒÎò´ÏÎí·æÌÝÏéÃ¨À«Óþ³ï´ÔÇ£ÃùÉò¸óÄÂÇüÖ¼ÐäÁÔ±ÛÉßºØÖùÅ×ÊóÉª¸êÀÎÑ·ÂõÆÛ¶ÖÇÙË¥Æ¿ÄÕÑàÖÙÓÕÀÇ³ØÌÛÂ¬ÕÌ¹ÚÁ£Ò£ÂÀÐþ³¾·ë¸§Ç³¶Ø¾À×ê¾§ÆñÏ¿²ÔÅçºÄÁèÇÃ¾úÅâÍ¿´â±â¿÷¼ÅÃºÐÜ¹§ÊªÑ­Å¯ÌÇ¸³ÒÖÖÈÃ±°§ËÞÌ¤ÀÃÔ¬ºî¶¶¼ÐÀ¥¸Î²ÁÖíÁ¶ºãÉ÷°áÅ¦ÎÆ²£Óæ´ÅÍ­³Ý¿çÑº²ÀÄ®Æ£ÅÑÇ²¼À×íÈ­ÃÖÐ±µµÏ¡½Ý·ôÖ×Òß¶¹Ï÷¸Ú»ÎÍÌºê°©¶ÇÁ¥ÂÄÕÇÒ«Å¤Ì³ÎÖ²¦»æ·¥¿°ÆÍ¹ùÎþ¼ßÄ¹¹ÍÁ®ÆõÆ´³Í×½¸²Ë¢½ÙÏÓ¹ÏÐªµñÃÆÈé´®ÍÞ½É»½Ó®Á«ÌÒ°ÔÍ×ÊÝ´î¸°ÔÀ¼Î²Õ¿¡Ö·ÅÓ¸ûÈñ·ì»ÚÑûÁá³âÕ¬ÌíÍÚºÇËÏÑõºÆÓð½ï¿áÂÓÑý»öÊÌÒÒ·ÁÌ°ÕõÍôÄòÀòÐü´½º²²Ö¹ìÃ¶ÑÎÀÀ¸µË§Ãí·ÒÆÁËÂÅÖÁ§ÓÞµÎÊèÏô×Ë²ü³óÁÓ´çÈÓ¶¢ÈèÆ¥¾ã±æ¶ö·äÇ»ÓôÀ£½÷Ôã¸ðÃç³¦¼ÉÁïºè¾ôÅôÓ¥ÁýÇð¹ð×ÌÁÄµ²¸Ù¼¡¿ÇºÛÍëÑ¨°ò×¿ÏÍÎÔÄ¤ÒãÇ·½õÁ¨º¯Ã£°ºÑ¦Öå¿äÔ¥Î¸Éà°þ°ÁÊ°ÎÑÕöÐ¯ÁêºßÃÞÇçÁåÌîËÇ¿ÊÎÇ°çÄæ´à´­ÕÖ²·Â¯²ñÓäÉþÌ¥ÐîÃß½ßÎ¹ÉµÄ½»ë¼éÉÈ¹ñÔÃÀ¹µ®±¥Ç¬ÅÝÔôÍ¤Ï¦µù³êÈåÒöÂÑ·ÕÐ¹¸Ë°¤É®ÃÛÒ÷ÐÉËìÏÁÐ¤ÌðÏ¼²µÔ£ÍçÕª°«ÃëÇäÐóÑÊÅû¸¨¹´Åè½®¶ÄËÜÎ·³³ÄÒ²´·ÎÖè²ø¸ÔÐßµÉµõÂ©¼Ö°ßÌÎÓÆÂ¹·ýÎý±°ÔáÃúÌ²¼Þ´ß³áºÐÂùÅËÆç´Í¹øÀÈ²ð¹àÃãÃ¤Ô×É¶ÕÍ³¶ÁÉÄ¨Í²Æå¿ã°¦ÆÓ¸ÀÔÐÊÄºíÍý¾ÐÁ´³ÛÀ¸ÊÅÇÔÑÞÏË³ô¿Ã³Ã½³Ó¯ÎÌ³îË²Ó¤Ð¢¾±ÌÈÕãÁÂ±Î³©ÔùÎ¾¶³¹ò´³ÆÏÑ¼³øµßÕÚÒêÓõÂØ±ÙÁöÉ©¿òÌ·ÇÕÓ¹Ç¸Ö¥ºð¸¦ÉÀÑçÌ¯ÖöÖÔ½¿ÉÂ¾ØÆÖÑÈËÊÂã±Ì´ÝÐ½ÁÜ³Ü½ºÍÀ¶ì¼¢ÅÎ²±ºç´ä±ÀÕËÆ¼·ê×¬³ÅÏè³«Ãà¿ÝºïÎ×ÕÑÕúÔ¨´ÕÏª´À²ûÍúÔ¢ÌÙÉ¡·Ë±®Å²ÇíÖ¬»Ñ¿®ÆÐÌÑÊ¨¾ò³­ÁëÔÎ¿³´þÌÍÎúº±ÍìÆ¢ÖÛ³Õ¼ô¼¹¹­ÀÁ²æ¹ÕÁÅ¾èæ¢É§ÍØÍáÕ³±ú¿ÓÄ°Õ­ÏæÕ×ÑÂ½¾É²±ÞÃ¢½îÆ¸¹³¹÷ÈÂÏÙÏÒÑæË£¸©ÀåÏÃ¿ÒÈÄ¶¤¹Ñº¶Ë¤µþÈÇÓ÷Æ×À¢»Í»ÕÈÜ×¹É·½íÀÄÈ÷¶Â´ÉÖäÒÌ°ôÔ¡ÃÄ»´°¥ÆáÆ¨Òù³²·Ô×«Ð¥ÖÍÃµË¶µöµûÏ¥Ò¦Ã¯ÇûÀôÔ³Õ¯Ë¡ÇþÆÝ³½²°°ä»Ìºü·í±¿ÅÛ³°ÆÃ·ÈÏÎ¾ëº­È¸Ñ®Ëº½©Ö«Â¢ÒÄÒÝÃ©ÇÈÓßÒ¤ÆÑÇ«º¼±×Ñ«¹Î½¼ÆàÅõ½þ×©¶¦ÀºÕôÄ¶±ýÉö¶¸×¦ÍÃÒóÕê¼öÑÆÌ¿·ØÕ£²«Â£¿È¾ËÃÁÉÃË¬¿§¸é´ÆÉÚ¹®¾îÂÝ¹üÎôÐùÃýµý¹êÏ±½ªÏ¹Ô©Ñ»ÅîÏïÁÕÔÔÕ´Õ©Õ«Â÷±ë×É·Ä¹ÞÍ°ÈÀËÌ¸âÅòÐ³ÀÝ¹¾Ï¶À±°ó³èºÙ¶ÒÃ¹´ì»ü·øÆòÉ´È¹ÐåÕÈÌÁÑÜÖáÅÊ²²Æ©ÆíÌßËÁ¿²½ÎÅïÆüÂÅÔê»ËÒç×µÔÒÌËÁ±·«ÆÜ´ÜÍèÕ¶µÌËú··ÏáÏÆ¹ÔÃÕÄóÑÖÂ²±õ³×Â«Æ»Ð¶ÕÓÔ¿Öêµ»ÆÊÎõ»©ÅüÇÓÌÄ¸ì×®¹åÓéÈ¢Ä­É¤¶×ÌÔ·ÙÄÛÔÏ³ÄÐÙÊú¾û¾þ±ªÀÌ¾Õ±ÉÆÇ¶µºåÓ±Ð¼ÒÏºøÉøÍººµÓ´ÏÌÍðÇ´µ¾Öý¶Í±Ð»Ð±áÖòº§Ð¾Ö­·»Â¿Ðà¾¸Ó¶ÂµÆù¼½¾£´ÞÑãÉðÉº°ñËÐ°ø´¼µÑÇÝÎðÃé´±¿Ü»ß¶Ã²ÈÎØ¹°Ãï¸¿¹îÑÍÅñÍóÖó×ä¿±¶º¼úµé³´²Ó³¨À¯ÇôÀõ¹¼µæ¶Ê¿ýÒ¥Ä¯Ë¦ÊñÕíÑÄØ¤Ó¾ÃÚÓâ¶£ÔïÖÀÊàÔ÷¾¨ÒÐÎê·÷º×Ê´½¬Ü½À¬¿¾É¹Ëª½ËÔÌ»øÓì³ñÇâÍÕ×±À¦Ç¦¹äÊçÁñ±ûÑ÷³®ÌãÈ®¹ªÖçÔåÖëºÖ¼ÕµìÄ¼µ¢µ¸ÂªÂÂÖ¶Å°¶éÓ¨½Æ·§½Ê¿å¸à¾¥ÃåÀ®ÈÞ½ÁµÊËóÅ¥¹×¹¢µÞÐ¸¼µÔîÔÈ¸ëÔèÔäÎ³·ÐÈÐ³ë¶ôË¸Ðá°È°¾ÉÝ×¾¶°ÌºÍ©É°ÐºÃ§ÆºÊáÉ¼ÎîÖÉÊßÓ¬Çêµ·ÁòÏÛ½ÀÂÙ»¦¿õ±òÑ¿ÀêÌ¼ßÖÌèÊîÂÜÐÚÐÈ¿ú°³Ì¶Æé¼ñÕü³ÎÎ®ÎÐÌÏÏ¾ËÝÁÛÄðÒðãµÄºÑÃ½ë¸«»À×ØÓÓË»¼ËÐúÈØÉ¾Ó£ËÅÎËÉÒ°Ó²Ï·óÀ½ÐÓÒ±ÄÓ±ÓÂ§ÄôÍñÔë¼Ú÷¢ÁâÕµÄäÖ¨ÇÞÀ¿Ëè±üÊ¸²¸ÖÄËÔÐ®¸×ÈàÄåÑ±ÀÂÉÎÌ±ÖüÃÙëüÆ§ÂûÇ¶ÅÏËöµúÉ¬ëÊ±Ä½óß¶Ðñ¾÷Ïº²¾Æ¡ÇÜÔæÅ»ÂæÍ¹Ï¨ÉÑ°¼ÊêÍÍÌÅ½½×ÆÅé¼¬ÏðÁû¼îÀÑÃÈ¾ÚÇÎÆ²ËÚ·à¹¶Âì¼óÌû¼åÂÆ´ØÀâÄÅÝºÊûÌÌÍÜÁæ´õ´ÐÏøÀ¤Àª»äÌäÕ§°ê½ÃÍ÷°Ï¹£²Þ×Á¼¥¿ßÁ²Â®ÅßÉë´Â¶ó¸Í¿¶´¸Ë¨½°ÎÃ°õÄõ²Ñ´ÁÙ÷½¦¸Æ½¸ÕÃÃÐ»íÁ×ÓØÕ°Â­Áðµ¿ºû¼ðÃì¾ìÃõÌ­ÉôÏâ¿»»ÂÅ¿±Á¾½Ïù×Ã×ÇÊÈº³¿¸ÇÍÇÌ¿Ä²ÛÕ¤ÌÊÍÇÑ¬Äµ×º»²Àæ·¾Ìé±¹Ä¡õâÖâÈÛÖ¿ÂÈÒïÁÝÊü¸¬ÄÀÇÏÖàâÖ²×µ¡ÞÈÁü°±´£¿øÄ´Åæ´§Õ¸¾Ï¿ÑÇ¢ÍÙ³÷Ö©ÌµÍà¼í²õÐ·¾éÇæ°Ì²ù¶ÛÏ»Ã¥»¡×¶¾¾¸Ü¿ÔÎÜÊãº·ÃÒ»Þ´×¾âØ²º¾³Þ»«ÅÇÏõÔí¶æàÂ±·Ñ¥Îæ´¯¿Á»à´ê½´ÁÞéÜ½¶Ì¦Éâ¶ÐÏÏ¿êÎÉÐöÁÈ¾¤²ÚØÔ»±°ÇÐõ°ÅÌë»¾ÕÀÏüÒØ²íÇÑ¶üÈÍ±ï·ÞÐÆ´¾ÔÁ°¯±ô»ûÎëÌÞÀéµí»£ÂàÖºÕå°°°âË©×çÅ³Àç³ÑÅ¡º¥°íÈù½·Îµ¿ôÕ»Þ±°¹ÆÙÔü¹Óß´ÍÎÎ¡¾ÎÀðÕÞ°ÃÐôÕîÂÁµÓÊÑÆöÀãÚåÍÝ·ã¿½¶ßÎ­ôæÖÏÒÈ°ÐÎß±èº¿»ÏµèºùÂË²ÇØ°°ùàÍº´·õñ«ÏýÈïºæÔþÂ¸ÓÜ»È¿¥É×Õ¢·®¹¸ÎÁ¹½ÌêìÅÄçÔÉÔßàÖÉÅÑ³Ãö²ô¶èÔûÍÖßäö®½ÑìôÀß³ÀÀÙ¹è´¶òðÊÃÊºÍÊËíÈ×Ç¯¿Ð¹ëÌòµÅ¸¤ÊÁÅ¹Îà³Ú½ÄÍ±ÔÍÊí³ºÐâ³íÅØÅ¸æÒÅ§ÂâËëÐÏ²óÊïÓçÉ¸ÚË±Ô²þ¸Ø¶êßëÓ«ÊþÈÁ´ÛØ¬áãËîÀìôáÇº¿ðÌ´·ÍÍÔ¾æÓ©óÝÅùÀÓð¯Ëâ²ºÆ¹×ÄÕ±ÈìÉ¦ËñÄüÃá°ªÅëÑÙãåÓ½ÆÔÄíã²ÄÆ´·°ÀÅìµª³ûÑß´éðÐÏ¬¹ÁéÏÆþØÒÃªÅÒÒ¾Áßã¾»åÀùÈäëÈÁÃËÖÑí¸ÈÈµ¸íÄ¢¿¬Ð¿½Íá£°ý×á¾ó·Ì³úÔÜö¨´ñßº¶Õ´ÑÎ¦ÑêÀþ×ÑÌ»°è³È×¸ÓÙ¿ûº¨ÀÅô¤ºÌèµÍïÒ¸Á»Á¤ÉÓ¸áé­¼ëðÄéÙÇË°ÊÈ¬ÅÙÍÉÑèÂøÞÖÖãóïµóçÔÈß½ÈËôÑÑÙËÕ¥µï¼ÏÀÒ¿«Ì£µâÄëÀÞ¾ÔÑúË±µð¿¢äö²äÃÓÌñõÎÎÏº©¸òÍ«Æ°ÇÛ³Ó¶åÁÊÂ±µÕ÷ÞµëÃêßóÑ´îíÃó²³¹¿ÏÚ¹¯ÏÑó¬öù¶ï·¤Å÷ÂÍ²çó°ÄìçÍ°ú±Ã¼ØÉû±ñõåÅÈõïÁ­½§òùÆêÔ¯»ÁÞà½Õ²öÁþÐ¨Àóó¡ÒÙçÖèëÒ´Ô§ÂÕ¿ÀÎÍõËÓ»óÏ·¡ÉÄ¸þÁÀòÚÅºÐ«Ò¬¶ÆÅ¢ó¦ÃÊÈ³ÕºÕá¿þ°ö±º¹ô±îÓ¼ÑìÖûÇ­ÀÜÖÑ½æ¿æ¶âÊ­Â¨µà¾Ä×»»×ÔÅ±¢ò½ÁÇòßÕøé¹Â¦ÔéÌÂÜÔ°ðÕÁá«¾ÊÑ¢çèâÉÍ®òÑêÇº¸ñÉò¾¿Ùò¼¶»Á¡òòòÇ¼ÔÑâ°ÒéÅ¸ÑÓ§ÇÂÃäÅ±ÄÙ¿·ÈÒÀÔÈòÐï´»öê¶§ÃÌÅ´Íãíïëç¸äñ®¾Âë¹Öô¹¡Óó²òÇùÄûêþê¼¸Ì»çìªÒ¨ÝïÍÒ²êÀÆ²t»þÉÖëýÈþµ§ÁÍÑÁîõÂáâ¬×ÂÕ¡ÉÞàÒ×Òè¾¿èäÌ²¤¶ÚòÈº»é»·¯ÅðÉ»¸ÝàÚÏÇÒ¼ñÃÁóÄèÏ³ÆèÑäï±±ìóÔ±ÍÌÜÜñÈ¿¾ÁÊòÃøÙìÃ­ÜîÄ÷ÒÞ°ÆéÝÜùôïïøó¨Ý©ïõÆâ";
	return chineseTable;
}
static unsigned short getRandomValue(const unsigned short minValue, const unsigned short maxValue)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(minValue,maxValue);
	return dis(gen);
}
int main()
{
	const int srcSize = 86;
	const int standardSize = 32;
	const auto font = R"(·½ÕýÐÂÊéËÎ¼òÌå.ttf)";
	SampleGenetator paiter(font, srcSize);
	const auto chineseTable = getChineseTable();
	while (true)
	{
		const auto txtChar = chineseTable[getRandomValue(0, chineseTable.size())];		
		const auto srcImg = paiter.genSample(txtChar);		
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
	return 0;
}