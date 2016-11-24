/**
 * @file
 * @copyright  Copyright 2016 GNSS Sensor Ltd. All right reserved.
 * @author     Sergey Khabarov - sergeykhbr@gmail.com
 * @brief      Halt simulation.
 */

#include "cmd_halt.h"

namespace debugger {

CmdHalt::CmdHalt(ITap *tap, ISocInfo *info) 
    : ICommand ("halt", tap, info) {

    briefDescr_.make_string("Stop simulation");
    detailedDescr_.make_string(
        "Description:\n"
        "    Stop simulation.\n"
        "Example:\n"
        "    halt\n"
        "    stop\n"
        "    s\n");
}


bool CmdHalt::isValid(AttributeType *args) {
    AttributeType &name = (*args)[0u];
    if (name.is_equal("halt") || name.is_equal("break") 
        || name.is_equal("stop") || name.is_equal("s")) {
        return CMD_VALID;
    }
    return CMD_INVALID;
}

void CmdHalt::exec(AttributeType *args, AttributeType *res) {
    res->make_nil();
    if (!isValid(args)) {
        generateError(res, "Wrong argument list");
        return;
    }

    Reg64Type t1;
    DsuMapType::udbg_type::debug_region_type::control_reg ctrl;
    ctrl.val = 0;
    ctrl.bits.halt = 1;
    t1.val = ctrl.val;
    tap_->write(info_->addressRunControl(), 8, t1.buf);
}

}  // namespace debugger
