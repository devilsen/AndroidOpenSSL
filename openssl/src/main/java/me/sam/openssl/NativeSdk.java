package me.sam.openssl;

/**
 * desc : Native SDK
 * date : 2020/3/19 6:26 PM
 *
 * @author : dongSen
 */
public class NativeSdk {

    static {
        System.loadLibrary("openssl");
    }

    private NativeSdk() {
    }

    public static NativeSdk getInstance() {
        return Holder.instance;
    }

    private static class Holder {
        private static final NativeSdk instance = new NativeSdk();
    }

    public native String md5(String text);

    public native String base64Encode(String text);

    public native String base64Decode(String text);

//    public native String aesEncode(String text, String key);

//    public native String aesDecode(String text, String key);


}
