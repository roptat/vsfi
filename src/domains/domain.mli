(*
    This file is part of BinCAT.
    Copyright 2014-2017 - Airbus Group

    BinCAT is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    BinCAT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with BinCAT.  If not, see <http://www.gnu.org/licenses/>.
*)

open Data

(** Signature of abstract domains *)

module type T = 
    sig
      (** type of abstract values *)
      type t 

      (** make all computed dimensions to top *)
      val forget: t -> t

      (** comparison to top *)
      val is_top: t -> bool
		 
      (** returns true whenever the concretization of the first argument is included in the concretization of the second argument ;
	false otherwise *)
      val is_subset: t -> t -> bool
 	       
      (** string conversion *)
      val to_string: t -> string
				     
      (** joins the two abstract values *)
      val join: t -> t -> t

      (** meets the two abstract values *)
      val meet: t -> t -> t

      (** widens the two abstract values *)
      val widen: t -> t -> t
    end
