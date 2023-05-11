#include "usageExamples.h"


static double sum( const std::vector<double>& v ) {
    double total = 0.0;
    int n = v.size();
    for (int i=0; i<n; i++) {
        total += v[i];
    }
    return total;
}
 
void writeHaiku( std::ostream& out ) {
   out << "The wren\n";
   out << "Earns his living\n";
   out << "Noiselessly.\n";
}
 
void testWriteHaiku() {
   // write a Haiku to cout
   writeHaiku( std::cout );
   // write a Haiku to a file
   std::ofstream out;
   out.open("haiku.txt");
   writeHaiku( out );
   out.close();
}
 
 
void writeCSVChartData( std::ostream& out,
        const std::vector<double>& x,
        const std::vector<double>& y ) {
    ASSERT( x.size()==y.size());
    int n = x.size();
    for (int i=0; i<n; i++) {
        out << x[i] <<","<<y[i] <<"\n";
    }
}
void writeCSVChart( const std::string& filename,
        const std::vector<double>& x,
        const std::vector<double>& y ) {
    std::ofstream out;
    out.open( filename.c_str() );
    writeCSVChartData( out, x, y );
    out.close();
}
 
void testSum() {
  std::vector<double> v;
  v.push_back(1.0);
  v.push_back(2.0);
  sum(v);
}
 
void testUsageExamples() {
    testWriteHaiku();
    testSum();
}