/**
 * @file
 * @copyright  Copyright 2016 GNSS Sensor Ltd. All right reserved.
 * @author     Sergey Khabarov - sergeykhbr@gmail.com
 * @brief      Read/write memory.
 */

#ifndef __DEBUGGER_CMD_READ_H__
#define __DEBUGGER_CMD_READ_H__

#include "api_core.h"
#include "coreservices/icommand.h"

namespace debugger {

class CmdRead : public ICommand  {
public:
    explicit CmdRead(ITap *tap, ISocInfo *info);

    /** ICommand */
    virtual bool isValid(AttributeType *args);
    virtual void exec(AttributeType *args, AttributeType *res);

private:
    void to_string(AttributeType *args, AttributeType *res, AttributeType *out);

private:
    AttributeType rdData_;
};

}  // namespace debugger

#endif  // __DEBUGGER_CMD_READ_H__
