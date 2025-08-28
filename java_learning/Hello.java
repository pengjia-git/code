import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Iterator;
import java.io.*;

public class Hello {
    public static void main(String[] args) throws IOException {
                byte[] data = "hhellhho, world!".getBytes("UTF-8");
        CountInputStream ci=new CountInputStream(new ByteArrayInputStream(data));
        //try (CountInputStream input = new CountInputStream(new ByteArrayInputStream(data))) {
            try(CountSpecInputStream input = new CountSpecInputStream(ci)){
            int n;
            while ((n = input.read()) != -1) {
                System.out.println((char)n);
            }
            System.out.println("Total read " + input.getSpecBytesRead() + " bytes");
            System.out.println("Total read " + ci.getBytesRead() + " bytes");
        }
    }
}

class CountInputStream extends FilterInputStream {
    private int count = 0;

    CountInputStream(InputStream in) {
        super(in);
    }

    public int getBytesRead() {
        return this.count;
    }

    public int read() throws IOException {
        int n = in.read();
        if (n != -1) {
            this.count ++;
        }
        return n;
    }

    public int read(byte[] b, int off, int len) throws IOException {
        int n = in.read(b, off, len);
        if (n != -1) {
            this.count += n;
        }
        return n;
    }
}


class CountSpecInputStream extends FilterInputStream {
    private int count = 0;

   CountSpecInputStream(InputStream in) {
        super(in);
    }

    public int getSpecBytesRead() {
        return this.count;
    }

    public int read() throws IOException {
        int n = in.read();
        if (n != -1 && n == 104) {
            this.count ++;
        }
        return n;
    }

    public int read(byte[] b, int off, int len) throws IOException {
        int n = in.read(b, off, len);
        if (n != -1) {
            for(int i=0;i<n;i++)
                if(b[i]== 104)
                    this.count ++;
        }
        return n;
    }
}