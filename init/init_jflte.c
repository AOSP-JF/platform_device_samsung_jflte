/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void gsm_properties();
void cdma_properties(char cdma_sub[]);
void r970_properties();

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "I337M")) {
        /* jfltecan */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jfltevl/jfltecan:4.2.2/JDQ39/I337MVLUAMDJ:user/release-keys");
        property_set("ro.build.description", "jfltevl-user 4.2.2 JDQ39 I337MVLUAMDJ release-keys");
        property_set("ro.product.model", "SGH-I337M");
        property_set("ro.product.device", "jfltecan");
    } else if (strstr(bootloader, "I337")) {
        /* jflteatt */
        gsm_properties();
        property_set("ro.product.device", "jflteatt");
        property_set("ro.product.model", "SAMSUNG-SGH-I337");
        property_set("ro.build.fingerprint", "samsung/jflteuc/jflteatt:5.0.1/LRX22C/I337UCUGOC3:user/release-keys");
        property_set("ro.build.description", "jflteuc-user 5.0.1 LRX22C I337UCUGOC3 release-keys");
    } else if (strstr(bootloader, "R970C")) {
        /* jfltecri */
        cdma_properties("0");
        r970_properties();
        property_set("ro.build.fingerprint", "samsung/jfltecri/jfltecri:4.2.2/JDQ39/R970CVVUAME4:user/release-keys");
        property_set("ro.build.description", "jfltecri-user 4.2.2 JDQ39 R970CVVUAME4 release-keys");
        property_set("ro.product.model", "SCH-R970C");
        property_set("ro.product.device", "jfltecri");
        property_set("ro.cdma.home.operator.alpha", "Cricket");
        property_set("ro.cdma.home.operator.numeric", "310090");
    } else if (strstr(bootloader, "R970X")) {
        /* jfltecsp */
        cdma_properties("0");
        r970_properties();
        property_set("ro.build.fingerprint", "samsung/jfltecsp/jfltecsp:4.2.2/JDQ39/R970XWWUAMFA:user/release-keys");
        property_set("ro.build.description", "jfltecsp-user 4.2.2 JDQ39 R970XWWUAMFA release-keys");
        property_set("ro.product.model", "SCH-R970X");
        property_set("ro.product.device", "jfltecsp");
        property_set("telephony.sms.pseudo_multipart", "1");
    } else if (strstr(bootloader, "L720")) {
        /* jfltespr */
        cdma_properties("1");
        property_set("ro.build.fingerprint", "samsung/jfltespr/jfltespr:4.2.2/JDQ39/L720VPUAMDL:user/release-keys");
        property_set("ro.build.description", "jfltespr-user 4.2.2 JDQ39 L720VPUAMDL release-keys");
        property_set("ro.product.model", "SPH-L720");
        property_set("ro.product.device", "jfltespr");
        property_set("ro.cdma.home.operator.numeric", "310120");
        property_set("ro.cdma.home.operator.alpha", "Sprint");
        property_set("ro.telephony.default_network", "8");
        property_set("ro.telephony.get_imsi_from_sim", "true");
        property_set("telephony.sms.pseudo_multipart", "1");
    } else if (strstr(bootloader, "M919")) {
        /* jfltetmo */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jfltetmo/jfltetmo:4.4.4/KTU84P/M919UVUFNK2:user/release-keys");
        property_set("ro.build.description", "jfltetmo-user 4.4.4 KTU84P M919UVUFNK2 release-keys");
        property_set("ro.product.model", "SGH-M919");
        property_set("ro.product.device", "jfltetmo");
    } else if (strstr(bootloader, "S970")) {
	/* jfltetfntmo */
	gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jfltetfntmo/jfltetfntmo:4.2.2/JDQ39/S970GUDUAMH3:user/release-keys");
        property_set("ro.build.description", "jfltetfntmo-user 4.2.2 JDQ39 S970GUDUAMH3 release-keys");
        property_set("ro.product.model", "SGH-S970G");
        property_set("ro.product.device", "jfltetfntmo");
	property_set("ril.subscription.types", "NV,RUIM");
        property_set("DEVICE_PROVISIONED", "1");
    } else if (strstr(bootloader, "S975")) {
	/* jfltetfnatt */
	gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jflteud/jfltetfnatt:4.3/JSS15J/S975LUDUANB1:user/release-keys");
        property_set("ro.build.description", "jflteud-user 4.3 JSS15J S975LUDUANB1 release-keys");
        property_set("ro.product.model", "SM-S975L");
        property_set("ro.product.device", "jfltetfnatt");
	property_set("ril.subscription.types", "NV,RUIM");
        property_set("DEVICE_PROVISIONED", "1");
    } else if (strstr(bootloader, "R970")) {
        /* jflteusc */
        cdma_properties("0");
        r970_properties();
        property_set("ro.build.fingerprint", "samsung/jflteusc/jflteusc:4.2.2/JDQ39/R970VXUAMD9:user/release-keys");
        property_set("ro.build.description", "jflteusc-user 4.2.2 JDQ39 R970VXUAMD9 release-keys");
        property_set("ro.product.model", "SCH-R970");
        property_set("ro.product.device", "jflteusc");
        property_set("ro.cdma.home.operator.alpha", "U.S.Cellular");
        property_set("ro.cdma.home.operator.numeric", "311580");
    } else if (strstr(bootloader, "I545")) {
        /* jfltevzw */
        cdma_properties("0");
        property_set("ro.build.fingerprint", "Verizon/jfltevzw/jfltevzw:5.0.1/LRX22C/I545VRUGOC1:user/release-keys");
        property_set("ro.build.description", "jfltevzw-user 5.0.1 LRX22C I545VRUGOC1 release-keys");
        property_set("ro.product.model", "SCH-I545");
        property_set("ro.product.device", "jfltevzw");
        property_set("ro.cdma.home.operator.alpha", "Verizon");
        property_set("ro.cdma.home.operator.numeric", "311480");
        property_set("ro.telephony.default_network", "10");
        property_set("ro.telephony.get_imsi_from_sim", "true");
        property_set("ro.config.multimode_cdma", "1");
        property_set("ro.config.combined_signal", "true");
        property_set("ro.gsm.data_retry_config", "max_retries=infinite,5000,5000,60000,120000,480000,900000");
        property_set("DEVICE_PROVISIONED", "1");
        property_set("ro.com.google.clientidbase", "android-verizon");
    } else if (strstr(bootloader, "I9505G")) {
        /* jgedlte */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jgedlteue/jgedlte:5.1/LMY47O.S008/150802:user/release-keys");
        property_set("ro.build.description", "jgedlteue-user 5.1 LMY47O.S008 150802 release-keys");
        property_set("ro.product.model", "GT-I9505G");
        property_set("ro.product.device", "jgedlte");
        property_set("ril.subscription.types", "NV,RUIM");
        property_set("DEVICE_PROVISIONED", "1");
    } else if (strstr(bootloader, "I9505")) {
        /* jfltexx */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jfltexx/jflte:5.0.1/LRX22C/I9505XXUHOB7:user/release-keys");
        property_set("ro.build.description", "jfltexx-user 5.0.1 LRX22C I9505XXUHOB7 release-keys");
        property_set("ro.product.model", "GT-I9505");
        property_set("ro.product.device", "jfltexx");
    } else if (strstr(bootloader, "I9507")) {
        /* jftddxx */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jftddxx/jftdd:4.3/JSS15J/I9507XXUENB5:user/release-keys");
        property_set("ro.build.description", "jftddxx-user 4.3 JSS15J I9507XXUENB5 release-keys");
        property_set("ro.product.model", "GT-I9507");
        property_set("ro.product.device", "jftddxx");
    } else if (strstr(bootloader, "I9508")) {
        /* jfltezm */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jfltezm/jflte:4.2.2/JDQ39/I9508ZMUAMG1:user/release-keys");
        property_set("ro.build.description", "jfltezm-user 4.2.2 JDQ39 I9508ZMUAMG1 release-keys");
        property_set("ro.product.model", "GT-I9508");
        property_set("ro.product.device", "jfltezm");
    } else if (strstr(bootloader, "I9295")) {
        /* jactivelte */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jactivelte/jactivelte:4.4.2/KTU84Q/I9295XXUCNE5:user/release-keys");
        property_set("ro.build.description", "jactivelte-user 4.4.4 KTU84Q I9295XXUCNE5 release-keys");
        property_set("ro.product.model", "GT-I9295");
        property_set("ro.product.device", "jactivelte");
    }

    property_get("ro.product.device", device);
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, device);

}

void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
}

void cdma_properties(char cdma_sub[])
{
    property_set("ro.telephony.default_cdma_sub", cdma_sub);
    property_set("ro.gps.set_privacy", "1");
    property_set("persist.eons.enabled", "false");
    property_set("persist.radio.snapshot_enabled", "1");
    property_set("persist.radio.snapshot_timer", "22");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void r970_properties()
{
    property_set("ro.telephony.default_network", "8");
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("telephony.sms.pseudo_multipart", "1");
    property_set("ro.config.combined_signal", "true");
    property_set("ro.gsm.data_retry_config", "max_retries=infinite,0,0,60000,120000,480000,900000");
    property_set("DEVICE_PROVISIONED", "1");
}
