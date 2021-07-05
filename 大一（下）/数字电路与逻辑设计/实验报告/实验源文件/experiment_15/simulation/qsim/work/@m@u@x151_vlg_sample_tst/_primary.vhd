library verilog;
use verilog.vl_types.all;
entity MUX151_vlg_sample_tst is
    port(
        Address         : in     vl_logic_vector(2 downto 0);
        d0              : in     vl_logic_vector(3 downto 0);
        d1              : in     vl_logic_vector(3 downto 0);
        d2              : in     vl_logic_vector(3 downto 0);
        d3              : in     vl_logic_vector(3 downto 0);
        d4              : in     vl_logic_vector(3 downto 0);
        d5              : in     vl_logic_vector(3 downto 0);
        d6              : in     vl_logic_vector(3 downto 0);
        d7              : in     vl_logic_vector(3 downto 0);
        sampler_tx      : out    vl_logic
    );
end MUX151_vlg_sample_tst;
