
import java.io.IOException;
import java.net.*;
public class datagram_socket
  {

    public static void main(String[] args) throws IOException
      {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName("localhost");
        int port = 5252;
        String str1= "hello";
        byte[] byteBuffer = str1.getBytes();
        DatagramPacket packet = new DatagramPacket(byteBuffer,str1.length(), address, port);
        DatagramPacket packetReceive = new DatagramPacket(new byte[1024], 1024);
        socket.send(packet);
        System.out.println("The packets are sent successfully");
        socket.receive(packetReceive);
        String msg = new String(packetReceive.getData(), packetReceive.getOffset(), packetReceive.getLength());
        System.out.println("The packet data received are: " + msg );

      }
  }
