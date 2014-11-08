/*
 * =====================================================================================
 *
 *       Filename:  pb_rpbc_server.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月25日 03时18分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  piboye
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __PB_RPC_SERVER_H_INC__
#define __PB_RPC_SERVER_H_INC__
#include <string>

#include "rpc_pb_server_base_impl.h"

#include "http_server.h"
#include "tcp_server.h"
#include "../../base/incl/obj_pool.h"
#include "base/incl/net_tool.h"
#include "google/protobuf/message.h"
#include "cmd_base.h"

namespace conet
{

struct tcp_server_t;
struct http_server_t;
struct rpc_pb_server_base_t;

struct rpc_pb_server_t
{
    tcp_server_t * tcp_server;
    http_server_t *http_server;

    rpc_pb_server_base_t * base_server;
    std::string http_base_path;
    obj_pool_t m_packet_stream_pool;
    

    rpc_pb_server_t();

    int init(
        rpc_pb_server_base_t *base_server,
        tcp_server_t * tcp_server,
        http_server_t * http_server
        );

    int start();

    int stop(int wait_ms);

    PacketStream *alloc_packet_stream();
    int send_pb(int fd, cmd_base_t *, google::protobuf::Message *rsp=NULL);
};

}


#endif /* end of include guard */ 
