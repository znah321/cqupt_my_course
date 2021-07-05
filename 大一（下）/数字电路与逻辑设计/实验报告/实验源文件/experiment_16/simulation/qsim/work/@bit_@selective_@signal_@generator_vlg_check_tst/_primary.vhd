library verilog;
use verilog.vl_types.all;
entity Bit_Selective_Signal_Generator_vlg_check_tst is
    port(
        Address         : in     vl_logic_vector(2 downto 0);
        Dig             : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end Bit_Selective_Signal_Generator_vlg_check_tst;
