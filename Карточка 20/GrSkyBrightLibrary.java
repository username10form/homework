package GrSkyBrightLibrary;

import java.awt.*;
import java.awt.event.*;

public class GrSkyBrightLibrary extends Frame implements WindowListener {

    public void windowOpened(WindowEvent e) {};

    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    };

    public void windowClosed(WindowEvent e) {};
    public void windowIconified(WindowEvent e) {};
    public void windowDeiconified(WindowEvent e) {};
    public void windowActivated(WindowEvent e) {};
    public void windowDeactivated(WindowEvent e) {};

    public void paint(Graphics g) {

        Dimension rc = getSize();
        Insets in = getInsets();

        int RH = rc.width;
        int RW = rc.height;

        int minX = in.left;
        int maxX = RH - in.right;
        int minY = in.top;
        int maxY = RW - in.bottom;
        int x1, y1, x2, y2 ;
        int cr,cq,cb;
        int cx, cy, dx, dy;
        float wdk=3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;



        g.setColor(new Color(0x000000));
        String txt = "20";
        g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 24));
        int nf = g.getFontMetrics().stringWidth(txt);
        g.drawString(txt, 40, 50 );

        g.setColor(new Color(0x000000));
        txt = ",де\n\t" ;
        g.drawString(txt, maxX-375, 100 );

        txt =        "a=9 (24*9);" ;
        g.drawString(txt, maxX-375, 130 );
        txt =  "b=3 (24*3) ;" ;
        g.drawString(txt, maxX-375, 160 );
        txt = "c=5 (24*5) ;" ;
        g.drawString(txt, maxX-375, 190 );
        txt =      "d=1 (24*1) ;";
        g.drawString(txt, maxX-375,220 );

        g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 24));




        int a=9,b=3,c=5,d=1;
        //зображення буде збільшено в 24, разів для гарного перегляду. Прпорції збережуться.
        x1=170;
        y1=60;
        g.drawLine(90,0,90,maxY);

        g.drawRect(x1,y1,a*24,a*24);
        g.drawLine(x1,y1,x1+a*24,y1+a*24);

        g.drawLine(x1+30,y1,x1+a*24,y1+a*24 -30 );
        g.drawLine(x1+60,y1,x1+a*24,y1+a*24 -60 );
        g.drawLine(x1+90,y1,x1+a*24,y1+a*24 -90 );
        g.drawLine(x1+120,y1,x1+a*24,y1+a*24 -120);
        g.drawLine(x1+150,y1,x1+a*24,y1+a*24 -150);
        g.drawLine(x1+180,y1,x1+a*24,y1+a*24 -180);


        x1=170;
        y1=60;
        g.drawLine(x1,y1+30,x1+a*24-30,y1+a*24 );
        g.drawLine(x1,y1+60,x1+a*24-60,y1+a*24 );
        g.drawLine(x1,y1+90,x1+a*24-90,y1+a*24 );
        g.drawLine(x1,y1+120,x1+a*24-120,y1+a*24 );
        g.drawLine(x1,y1+150,x1+a*24-150,y1+a*24 );
        g.drawLine(x1,y1+180,x1+a*24-180,y1+a*24 );



        g.drawOval(x1+2*a,y1+2*a,24*a-4*a,24*a-4*a);
        g.setColor(new Color(0xFAE535));
        g.fillOval(x1+2*a,y1+2*a,24*a-4*a-1,24*a-4*a-1);
        g.setColor(new Color(0x000000));
g.drawOval(x1+11*a-4*a,y1+11*a,24*d-3*d,24*d-3*d);
g.drawOval(x1+11*a+4*a,y1+11*a,24*d-3*d,24*d-3*d);

//g.drawLine(x1+11*a-3*a,y1+11*a,x1+11*a-3*a + (24*d-3*d)/2,y1+11*a+(24*d-3*d)/2);
//попытка зарисовать маленькие круги линиями
        g.setColor(new Color(0xD8F3FF));
        g.fillRect(x1+a*5/2,y1+300,2*d*24+24*c,24*b+24*d);
        g.setColor(new Color(0x000000));
g.drawRect(x1+a*5/2,y1+300,2*d*24+24*c,24*b+24*d);
        g.setColor(new Color(0xFFFFFF));
g.fillRect(x1+a*5/2 ,(y1+300)+96,2*d*24+24*c,1);

        g.setColor(new Color(0x000000));
g.drawLine(x1+a*5/2+24*d,(y1+300)+125,x1+a*5/2 + 2*d*24+24*c-24*d,(y1+300)+125);

g.drawLine(x1+a*5/2 + 2*d*24+24*c-24*d,(y1+300)+125,x1+a*5/2+2*24*d+24*c,y1+300+24*b+24*d);
        g.drawLine(x1+a*5/2+24*d,(y1+300)+125,x1+a*5/2+2*24*d+24*c-24*c-48*d,y1+300+24*b+24*d);

        g.drawRect(x1+a*5/2+(2*d*24+24*c)/2-48*d,y1+300-24*b,24*d,24*b);
        g.drawRect(x1+a*5/2+(2*d*24+24*c)/2+24*d,y1+300-24*b,24*d,24*b);
        g.setColor(new Color(0xC4D1F7));
        g.fillRect(x1+a*5/2+(2*d*24+24*c)/2-48*d+1,y1+300-24*b+1,24*d-1,24*b-1);
        g.fillRect(x1+a*5/2+(2*d*24+24*c)/2+24*d+1,y1+300-24*b+1,24*d-1,24*b-1);
        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));

        //линии снизу, попытка
        /*
        g2.setStroke(new BasicStroke(1.0f));  // толщина равна 1
        g2.setColor(new Color(0x000000));
        g2.drawLine(x1+a*5/2,y1+300,x1+a*5/2+75,y1+a*5/2+400);
        g2.drawLine(x1+a*5/2+30,y1+300,x1+a*5/2+75+30,y1+a*5/2+400);
        g2.drawLine(x1+a*5/2+60,y1+300,x1+a*5/2+75+60,y1+a*5/2+400);
*/

        // TO DO
        wdk=1.5f;
        g2.setStroke(new BasicStroke(wdk));







    }

    public GrSkyBrightLibrary() {
        super("Задорожний Денис.10-Ми.");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }

}
