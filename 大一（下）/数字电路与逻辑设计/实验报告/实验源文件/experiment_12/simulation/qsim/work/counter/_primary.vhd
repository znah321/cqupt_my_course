library verilog;
use verilog.vl_types.all;
entity counter is
    port(
        Q               : out    vl_logic_vector(4 downto 0);
        clk             : in     vl_logic
    );
end counter;
