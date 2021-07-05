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

-- DATE "05/06/2020 19:26:48"

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

ENTITY 	\3mux\ IS
    PORT (
	Y : OUT std_logic;
	d0 : IN std_logic;
	d1 : IN std_logic;
	a0 : IN std_logic;
	d2 : IN std_logic;
	a1 : IN std_logic
	);
END \3mux\;

-- Design Ports Information
-- Y	=>  Location: PIN_43,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d2	=>  Location: PIN_71,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d0	=>  Location: PIN_56,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a1	=>  Location: PIN_55,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a0	=>  Location: PIN_52,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d1	=>  Location: PIN_51,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF \3mux\ IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Y : std_logic;
SIGNAL ww_d0 : std_logic;
SIGNAL ww_d1 : std_logic;
SIGNAL ww_a0 : std_logic;
SIGNAL ww_d2 : std_logic;
SIGNAL ww_a1 : std_logic;
SIGNAL \Y~output_o\ : std_logic;
SIGNAL \d1~input_o\ : std_logic;
SIGNAL \a0~input_o\ : std_logic;
SIGNAL \a1~input_o\ : std_logic;
SIGNAL \d0~input_o\ : std_logic;
SIGNAL \d2~input_o\ : std_logic;
SIGNAL \inst2|inst3~0_combout\ : std_logic;
SIGNAL \inst2|inst3~1_combout\ : std_logic;

BEGIN

Y <= ww_Y;
ww_d0 <= d0;
ww_d1 <= d1;
ww_a0 <= a0;
ww_d2 <= d2;
ww_a1 <= a1;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y10_N9
\Y~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|inst3~1_combout\,
	devoe => ww_devoe,
	o => \Y~output_o\);

-- Location: IOIBUF_X0_Y5_N22
\d1~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d1,
	o => \d1~input_o\);

-- Location: IOIBUF_X0_Y4_N1
\a0~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a0,
	o => \a0~input_o\);

-- Location: IOIBUF_X0_Y4_N22
\a1~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a1,
	o => \a1~input_o\);

-- Location: IOIBUF_X0_Y3_N1
\d0~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d0,
	o => \d0~input_o\);

-- Location: IOIBUF_X7_Y0_N22
\d2~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d2,
	o => \d2~input_o\);

-- Location: LCCOMB_X1_Y3_N0
\inst2|inst3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2|inst3~0_combout\ = (!\a0~input_o\ & ((\a1~input_o\ & ((\d2~input_o\))) # (!\a1~input_o\ & (\d0~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001000000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \d0~input_o\,
	datab => \a0~input_o\,
	datac => \a1~input_o\,
	datad => \d2~input_o\,
	combout => \inst2|inst3~0_combout\);

-- Location: LCCOMB_X1_Y3_N18
\inst2|inst3~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2|inst3~1_combout\ = (\inst2|inst3~0_combout\) # ((\d1~input_o\ & (\a0~input_o\ & !\a1~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \d1~input_o\,
	datab => \a0~input_o\,
	datac => \a1~input_o\,
	datad => \inst2|inst3~0_combout\,
	combout => \inst2|inst3~1_combout\);

ww_Y <= \Y~output_o\;
END structure;


