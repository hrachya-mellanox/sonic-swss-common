#ifndef __NOTIFICATIONPRODUCER__
#define __NOTIFICATIONPRODUCER__

#include <string>
#include <vector>

#include <hiredis/hiredis.h>
#include "dbconnector.h"
#include "scheme.h"
#include "logger.h"
#include "table.h"
#include "redisreply.h"
#include "json.h"

namespace swss {

class NotificationProducer
{
public:
    NotificationProducer(swss::DBConnector *db, std::string channel);

    void send(std::string op, std::string data, std::vector<FieldValueTuple> &values);

private:

    NotificationProducer(const NotificationProducer &other);
    NotificationProducer& operator = (const NotificationProducer &other);

    swss::DBConnector *m_db;
    std::string m_channel;
};

}

#endif // __NOTIFICATIONPRODUCER__
