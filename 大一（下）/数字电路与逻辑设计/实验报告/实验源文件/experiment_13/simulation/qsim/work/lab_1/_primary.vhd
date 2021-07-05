library verilog;
use verilog.vl_types.all;
entity lab_1 is
    port(
        H               : out    vl_logic_vector(6 downto 0);
        A3              : in     vl_logic;
        A2              : in     vl_logic;
        A1              : in     vl_logic;
        A0              : in     vl_logic
    );
end lab_1;
