#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>

extern void options(boost::asio::io_service*, int*);


void print(const boost::system::error_code& /*e*/
    ,boost::asio::deadline_timer *t, bool first, boost::asio::io_service* io_orig, int* id)
{
    std::cout<<"calling threads"<<*id<<std::endl;
    if(first)
    {
        boost::asio::io_service io;
        boost::asio::io_service::work work(io);
        t->expires_at(t->expires_at() + boost::posix_time::seconds(9));
        t->async_wait(boost::bind(print,
          boost::asio::placeholders::error, t,false, io_orig,id));
    }
    else
    {
        io_orig->post(boost::bind(options, io_orig, id));
    }
}

void options(boost::asio::io_service* io_orig, int* id)
{
    boost::asio::io_service io_timer;
    boost::asio::deadline_timer t(io_timer, boost::posix_time::seconds(1));
    t.async_wait(boost::bind(print,
        boost::asio::placeholders::error, &t, true, io_orig, id));
    io_timer.run();
    std::cout<<"called threads"<<std::endl;
}

void work_poster(boost::asio::io_service* io, int* id)
{
    io->post(boost::bind(options, io, id));
}

int main()
{
  
  boost::asio::io_service io;
  boost::asio::io_service io_enb;

  boost::thread_group threadpool;
  boost::thread_group threadpool_1;


  /*
   *  * This will start the ioService processing loop. All tasks 
   *   * assigned with ioService.post() will start executing. 
   *    */
  boost::asio::io_service::work work(io);
  boost::asio::io_service::work work_1(io_enb);

  /*
   *  * This will add 2 threads to the thread pool. (You could just put it in a for loop)
   *   */
  threadpool.create_thread(
              boost::bind(&boost::asio::io_service::run, &io)
          );
  threadpool.create_thread(
              boost::bind(&boost::asio::io_service::run, &io)
          );


  threadpool_1.create_thread(
              boost::bind(&boost::asio::io_service::run, &io_enb)
          );
  int id1 = 1;
  io_enb.post(boost::bind(work_poster, &io, &id1));
  int id2 = 2;
  io_enb.post(boost::bind(work_poster, &io, &id2));
  int id3 = 3;
  io_enb.post(boost::bind(work_poster, &io, &id3));
  
  threadpool.join_all();
  threadpool_1.join_all();

  return 0;
}

