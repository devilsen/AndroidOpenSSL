package me.sam.sample;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import me.sam.openssl.Openssl;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private static final String TAG = MainActivity.class.getSimpleName();

    private Openssl openssl;
    private EditText sourceEdt;
    private TextView resultTxt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        sourceEdt = findViewById(R.id.source_edit_text);
        resultTxt = findViewById(R.id.result_text);

        Button md5Btn = findViewById(R.id.md5_button);
        Button base64EncodeBtn = findViewById(R.id.base64_encode_button);
        Button base64DecodeBtn = findViewById(R.id.base64_decode_button);


        md5Btn.setOnClickListener(this);
        base64EncodeBtn.setOnClickListener(this);
        base64DecodeBtn.setOnClickListener(this);

        openssl = new Openssl();
    }

    @Override
    public void onClick(View v) {
        String source = sourceEdt.getText().toString();
        if (TextUtils.isEmpty(source)) {
            source = sourceEdt.getHint().toString();
        }

        int id = v.getId();
        switch (id) {
            case R.id.md5_button:
                showResult(openssl.md5(source));
                break;
            case R.id.base64_encode_button:
                showResult(openssl.base64Encode(source));
                break;
            case R.id.base64_decode_button:
                showResult(openssl.base64Decode(source));
                break;
        }
    }

    public void showResult(String result) {
        Log.d(TAG, "result  >>>>   " + result);
        resultTxt.setText(result);
    }
}
