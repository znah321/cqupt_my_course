library verilog;
use verilog.vl_types.all;
entity D_trigger is
    port(
        Q               : out    vl_logic;
        CLRN            : in     vl_logic;
        CP              : in     vl_logic;
        D               : in     vl_logic;
        PRN             : in     vl_logic
    );
end D_trigger;
