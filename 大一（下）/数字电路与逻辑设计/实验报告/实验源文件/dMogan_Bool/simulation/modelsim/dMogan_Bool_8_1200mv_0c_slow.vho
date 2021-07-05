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

-- DATE "04/24/2020 14:33:36"

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

ENTITY 	dMogan_Bool_1 IS
    PORT (
	YLeft : OUT std_logic;
	A : IN std_logic;
	C : IN std_logic;
	YRight : OUT std_logic;
	B : IN std_logic
	);
END dMogan_Bool_1;

-- Design Ports Information
-- YLeft	=>  Location: PIN_19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- YRight	=>  Location: PIN_45,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A	=>  Location: PIN_98,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C	=>  Location: PIN_44,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B	=>  Location: PIN_64,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF dMogan_Bool_1 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_YLeft : std_logic;
SIGNAL ww_A : std_logic;
SIGNAL ww_C : std_logic;
SIGNAL ww_YRight : std_logic;
SIGNAL ww_B : std_logic;
SIGNAL \YLeft~output_o\ : std_logic;
SIGNAL \YRight~output_o\ : std_logic;
SIGNAL \C~input_o\ : std_logic;
SIGNAL \A~input_o\ : std_logic;
SIGNAL \inst3~combout\ : std_logic;
SIGNAL \B~input_o\ : std_logic;
SIGNAL \inst2~combout\ : std_logic;

BEGIN

YLeft <= ww_YLeft;
ww_A <= A;
ww_C <= C;
YRight <= ww_YRight;
ww_B <= B;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y22_N16
\YLeft~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst3~combout\,
	devoe => ww_devoe,
	o => \YLeft~output_o\);

-- Location: IOOBUF_X0_Y9_N2
\YRight~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2~combout\,
	devoe => ww_devoe,
	o => \YRight~output_o\);

-- Location: IOIBUF_X0_Y10_N22
\C~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_C,
	o => \C~input_o\);

-- Location: IOIBUF_X26_Y0_N29
\A~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A,
	o => \A~input_o\);

-- Location: LCCOMB_X6_Y4_N0
inst3 : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3~combout\ = (\C~input_o\) # (\A~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \C~input_o\,
	datad => \A~input_o\,
	combout => \inst3~combout\);

-- Location: IOIBUF_X5_Y0_N29
\B~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B,
	o => \B~input_o\);

-- Location: LCCOMB_X6_Y4_N2
inst2 : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2~combout\ = (\A~input_o\) # ((\B~input_o\ & \C~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \B~input_o\,
	datac => \C~input_o\,
	datad => \A~input_o\,
	combout => \inst2~combout\);

ww_YLeft <= \YLeft~output_o\;

ww_YRight <= \YRight~output_o\;
END structure;


