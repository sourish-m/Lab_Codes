
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class datagram_server
  {

    public static void main(String[] args) throws IOException
      {
        DatagramSocket datagramSocket = new DatagramSocket(5252);
        
        byte buf[] = new byte[1024];
        DatagramPacket datagramPacket = new DatagramPacket(buf, 1024);
        datagramSocket.receive(datagramPacket);
        String msg = new String(datagramPacket.getData(), datagramPacket.getOffset(), datagramPacket.getLength());
        System.out.println("The packet data received are: " + msg);
        
        String str2 = "World";
        byte send[] = str2.getBytes();
        DatagramPacket sendpacket = new DatagramPacket(send, str2.length(), datagramPacket.getAddress(), datagramPacket.getPort());
        datagramSocket.send(sendpacket);
      }
  }
