import static java.lang.System.*;
import static java.lang.Math.*;
import static java.lang.Character.*;
import java.util.*;
import java.io.*;
import java.math.*;
import static java.math.BigInteger.*;
import java.awt.*;
public class ThePower
{
  class state implements Comparable< state >
  {
    long n; long steps;
    state( long nn, long ss ) { n=nn; steps=ss; }
    public int compareTo( state s )
    {
      return (steps<s.steps) ? -1 : 1 
      ;
      //return  ( n < s.n ) ? -1 : ( n > s.n? 1 : 0 ) ;
      
    }
  }
  long pw ( long x, int p )
  {
    long ret = 1;
    while( p != 0 )
    {
      if(p%2 == 1 ) ret *= x;
      x *= x;      
      p /= 2;
    }
    return ret;
  }
  
  public int count(long n)
  {
    if( n==1 ) return 0;
    PriorityQueue< state  > q = new PriorityQueue();
    q.add( new state(n,0) );
    
    while( q.size() > 0 )
    {  
 
      state cur = q.poll();
      if( cur.n ==1 ) return (int)(cur.steps - 1);
      System.out.println( cur.n + " " + cur.steps );
      for(int r=2; r <= 60; ++r )
      {
        double ri = pow( cur.n, 1.0/r );
        if( ri < 1 ) break;
        ri = round( ri );
        long nxt = (long)ri;
        long ns  = ( abs( pw(nxt, r ) - cur.n ) );
        q.add( new state( nxt,  cur.steps + ns + 1) );
      }
      
    }
    return -1;
    
    
  }
}