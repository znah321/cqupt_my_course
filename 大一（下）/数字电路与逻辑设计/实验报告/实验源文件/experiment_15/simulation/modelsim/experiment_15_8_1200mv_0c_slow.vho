-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Full Version"

-- DATE "06/10/2020 21:39:00"

-- 
-- Device: Altera EP3C16Q240C8 Package PQFP240
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIII;
LIBRARY IEEE;
USE CYCLONEIII.CYCLONEIII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	\Bit-Selective_Signal_Generator\ IS
    PORT (
	Address : OUT std_logic_vector(2 DOWNTO 0);
	CP : IN std_logic;
	dig : OUT std_logic_vector(7 DOWNTO 0)
	);
END \Bit-Selective_Signal_Generator\;

-- Design Ports Information
-- Address[2]	=>  Location: PIN_182,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Address[1]	=>  Location: PIN_41,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Address[0]	=>  Location: PIN_188,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CP	=>  Location: PIN_151,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dig[7]	=>  Location: PIN_114,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dig[6]	=>  Location: PIN_224,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dig[5]	=>  Location: PIN_177,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dig[4]	=>  Location: PIN_147,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dig[3]	=>  Location: PIN_174,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dig[2]	=>  Location: PIN_196,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dig[1]	=>  Location: PIN_173,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dig[0]	=>  Location: PIN_176,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF \Bit-Selective_Signal_Generator\ IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Address : std_logic_vector(2 DOWNTO 0);
SIGNAL ww_CP : std_logic;
SIGNAL ww_dig : std_logic_vector(7 DOWNTO 0);
SIGNAL \CP~input_o\ : std_logic;
SIGNAL \Address[2]~output_o\ : std_logic;
SIGNAL \Address[1]~output_o\ : std_logic;
SIGNAL \Address[0]~output_o\ : std_logic;
SIGNAL \dig[7]~output_o\ : std_logic;
SIGNAL \dig[6]~output_o\ : std_logic;
SIGNAL \dig[5]~output_o\ : std_logic;
SIGNAL \dig[4]~output_o\ : std_logic;
SIGNAL \dig[3]~output_o\ : std_logic;
SIGNAL \dig[2]~output_o\ : std_logic;
SIGNAL \dig[1]~output_o\ : std_logic;
SIGNAL \dig[0]~output_o\ : std_logic;

BEGIN

Address <= ww_Address;
ww_CP <= CP;
dig <= ww_dig;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X39_Y29_N30
\Address[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \Address[2]~output_o\);

-- Location: IOOBUF_X0_Y10_N2
\Address[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \Address[1]~output_o\);

-- Location: IOOBUF_X32_Y29_N9
\Address[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \Address[0]~output_o\);

-- Location: IOOBUF_X37_Y0_N30
\dig[7]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \dig[7]~output_o\);

-- Location: IOOBUF_X9_Y29_N2
\dig[6]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \dig[6]~output_o\);

-- Location: IOOBUF_X41_Y27_N16
\dig[5]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \dig[5]~output_o\);

-- Location: IOOBUF_X41_Y14_N9
\dig[4]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \dig[4]~output_o\);

-- Location: IOOBUF_X41_Y25_N23
\dig[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \dig[3]~output_o\);

-- Location: IOOBUF_X28_Y29_N16
\dig[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \dig[2]~output_o\);

-- Location: IOOBUF_X41_Y24_N2
\dig[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \dig[1]~output_o\);

-- Location: IOOBUF_X41_Y27_N23
\dig[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \dig[0]~output_o\);

-- Location: IOIBUF_X41_Y15_N8
\CP~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CP,
	o => \CP~input_o\);

ww_Address(2) <= \Address[2]~output_o\;

ww_Address(1) <= \Address[1]~output_o\;

ww_Address(0) <= \Address[0]~output_o\;

ww_dig(7) <= \dig[7]~output_o\;

ww_dig(6) <= \dig[6]~output_o\;

ww_dig(5) <= \dig[5]~output_o\;

ww_dig(4) <= \dig[4]~output_o\;

ww_dig(3) <= \dig[3]~output_o\;

ww_dig(2) <= \dig[2]~output_o\;

ww_dig(1) <= \dig[1]~output_o\;

ww_dig(0) <= \dig[0]~output_o\;
END structure;


