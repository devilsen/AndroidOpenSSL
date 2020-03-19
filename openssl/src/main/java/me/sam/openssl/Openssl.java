package me.sam.openssl;

/**
 * desc : OpenSSL for Android
 * date : 2020/3/19 6:33 PM
 *
 * @author : dongSen
 */
public class Openssl {

    public String md5(String text) {
        return NativeSdk.getInstance().md5(text);
    }

    public String base64Encode(String text) {
        return NativeSdk.getInstance().base64Encode(text);
    }

    public String base64Decode(String text) {
        return NativeSdk.getInstance().base64Decode(text);
    }
}
