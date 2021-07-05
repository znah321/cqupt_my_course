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

-- DATE "05/08/2020 14:23:07"

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

ENTITY 	block1 IS
    PORT (
	F : OUT std_logic;
	A : IN std_logic;
	B : IN std_logic;
	C : IN std_logic;
	D : IN std_logic
	);
END block1;

-- Design Ports Information
-- F	=>  Location: PIN_51,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A	=>  Location: PIN_18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B	=>  Location: PIN_9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C	=>  Location: PIN_6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D	=>  Location: PIN_231,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF block1 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_F : std_logic;
SIGNAL ww_A : std_logic;
SIGNAL ww_B : std_logic;
SIGNAL ww_C : std_logic;
SIGNAL ww_D : std_logic;
SIGNAL \F~output_o\ : std_logic;
SIGNAL \B~input_o\ : std_logic;
SIGNAL \C~input_o\ : std_logic;
SIGNAL \A~input_o\ : std_logic;
SIGNAL \D~input_o\ : std_logic;
SIGNAL \inst|sub|81~0_combout\ : std_logic;

BEGIN

F <= ww_F;
ww_A <= A;
ww_B <= B;
ww_C <= C;
ww_D <= D;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y5_N23
\F~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|sub|81~0_combout\,
	devoe => ww_devoe,
	o => \F~output_o\);

-- Location: IOIBUF_X0_Y26_N15
\B~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B,
	o => \B~input_o\);

-- Location: IOIBUF_X0_Y27_N15
\C~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_C,
	o => \C~input_o\);

-- Location: IOIBUF_X0_Y22_N1
\A~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A,
	o => \A~input_o\);

-- Location: IOIBUF_X7_Y29_N29
\D~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D,
	o => \D~input_o\);

-- Location: LCCOMB_X1_Y26_N8
\inst|sub|81~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|sub|81~0_combout\ = (\B~input_o\ & ((\C~input_o\ & ((\A~input_o\) # (\D~input_o\))) # (!\C~input_o\ & (\A~input_o\ & \D~input_o\)))) # (!\B~input_o\ & (\C~input_o\ & (\A~input_o\ & \D~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B~input_o\,
	datab => \C~input_o\,
	datac => \A~input_o\,
	datad => \D~input_o\,
	combout => \inst|sub|81~0_combout\);

ww_F <= \F~output_o\;
END structure;


