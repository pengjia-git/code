//package com.yiibai;

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.Line2D;
import javax.swing.JApplet;
import javax.swing.JFrame;

public class Line extends JApplet {
    public void init() {
        setBackground(Color.white);
        setForeground(Color.white);
    }

    public void paint(Graphics g) {
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g2.setPaint(Color.gray);
        int x = 8;
        int y = 9;
        g2.draw(new Line2D.Double(x, y, 200, 200));
        g2.drawString("画一条线的示例", x, 250);
    }

    public static void main(String s[]) {
        JFrame f = new JFrame("画一条线");
        f.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        JApplet applet = new Line();
        f.getContentPane().add("Center", applet);
        applet.init();

        f.pack();
        f.setSize(new Dimension(300, 300));
        f.setVisible(true);
    }
}