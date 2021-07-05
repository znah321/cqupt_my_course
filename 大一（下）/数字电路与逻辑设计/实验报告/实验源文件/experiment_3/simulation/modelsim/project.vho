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

-- DATE "04/30/2020 10:03:14"

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
	G : OUT std_logic;
	L : IN std_logic;
	P : IN std_logic;
	T : IN std_logic;
	Y : OUT std_logic;
	R : OUT std_logic
	);
END block1;

-- Design Ports Information
-- G	=>  Location: PIN_21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y	=>  Location: PIN_63,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- R	=>  Location: PIN_41,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- L	=>  Location: PIN_37,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- P	=>  Location: PIN_44,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- T	=>  Location: PIN_38,	 I/O Standard: 2.5 V,	 Current Strength: Default


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
SIGNAL ww_G : std_logic;
SIGNAL ww_L : std_logic;
SIGNAL ww_P : std_logic;
SIGNAL ww_T : std_logic;
SIGNAL ww_Y : std_logic;
SIGNAL ww_R : std_logic;
SIGNAL \G~output_o\ : std_logic;
SIGNAL \Y~output_o\ : std_logic;
SIGNAL \R~output_o\ : std_logic;
SIGNAL \P~input_o\ : std_logic;
SIGNAL \L~input_o\ : std_logic;
SIGNAL \T~input_o\ : std_logic;
SIGNAL \inst~combout\ : std_logic;
SIGNAL \inst8~0_combout\ : std_logic;
SIGNAL \inst12~0_combout\ : std_logic;
SIGNAL \ALT_INV_inst~combout\ : std_logic;

BEGIN

G <= ww_G;
ww_L <= L;
ww_P <= P;
ww_T <= T;
Y <= ww_Y;
R <= ww_R;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_inst~combout\ <= NOT \inst~combout\;

-- Location: IOOBUF_X0_Y21_N2
\G~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_inst~combout\,
	devoe => ww_devoe,
	o => \G~output_o\);

-- Location: IOOBUF_X3_Y0_N9
\Y~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst8~0_combout\,
	devoe => ww_devoe,
	o => \Y~output_o\);

-- Location: IOOBUF_X0_Y10_N2
\R~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst12~0_combout\,
	devoe => ww_devoe,
	o => \R~output_o\);

-- Location: IOIBUF_X0_Y10_N22
\P~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_P,
	o => \P~input_o\);

-- Location: IOIBUF_X0_Y12_N22
\L~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_L,
	o => \L~input_o\);

-- Location: IOIBUF_X0_Y11_N1
\T~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_T,
	o => \T~input_o\);

-- Location: LCCOMB_X1_Y11_N0
inst : cycloneiii_lcell_comb
-- Equation(s):
-- \inst~combout\ = (\P~input_o\ & (\L~input_o\ & \T~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \P~input_o\,
	datac => \L~input_o\,
	datad => \T~input_o\,
	combout => \inst~combout\);

-- Location: LCCOMB_X1_Y11_N2
\inst8~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst8~0_combout\ = \P~input_o\ $ (\L~input_o\ $ (\T~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \P~input_o\,
	datac => \L~input_o\,
	datad => \T~input_o\,
	combout => \inst8~0_combout\);

-- Location: LCCOMB_X1_Y11_N4
\inst12~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst12~0_combout\ = (\P~input_o\ & ((\L~input_o\) # (\T~input_o\))) # (!\P~input_o\ & (\L~input_o\ & \T~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \P~input_o\,
	datac => \L~input_o\,
	datad => \T~input_o\,
	combout => \inst12~0_combout\);

ww_G <= \G~output_o\;

ww_Y <= \Y~output_o\;

ww_R <= \R~output_o\;
END structure;


