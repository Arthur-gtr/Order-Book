#pragma once

#include <stdint.h>
#include <stdlib.h>


typedef struct Order {
    uint64_t order_id;
    uint64_t trader_id;
    uint64_t price;
    uint64_t quantity;
} Order;

typedef struct OrderQueue {
    Order *orders;
    size_t size;
    size_t capacity;
} OrderQueue;

typedef struct OrderBook
{
    OrderQueue asks;
    OrderQueue bids;
} OrderBook;